// Author: Daniel Khoury

#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

//////////////////////////////////////////////
// AD5293 Command Codes
//////////////////////////////////////////////

#define NOP 0x0
#define WRITE_WIPER_POS 0x1
#define READ_WIPER_POS 0x2
#define RESET_TO_MIDSCALE 0x4
#define ENABLE_WRITE 0x6
#define READ_CONTROL_REG 0x7
#define SHUTDOWN_DEVICE 0x8

#define BYTES_PER_SPI_TRANSFER 2

//////////////////////////////////////////////

//////////////////////////////////////////////
// AD5293 GPIO Connections
//////////////////////////////////////////////

// Reset for both devices: GPIO 60
// RDY: GPIO 48 for SPI0, 49 for SPI1

int rst_pin = 60;
int rdy0_pin = 48;
int rdy1_pin = 49;

FILE *rstHandle = NULL;
FILE *rdy0Handle = NULL;
FILE *rdy1Handle = NULL;

char getOrSetValue[4], GPIOString[4], GPIOValue[64], GPIODirection[64];

//////////////////////////////////////////////

//////////////////////////////////////////////
// SPI Data Structures and Parameters
//////////////////////////////////////////////

static const char *device1 = "/dev/spidev1.0";
static const char *device2 = "/dev/spidev2.0";
static uint8_t mode;
static uint8_t bits = 16; // For AD5293 digital pot
static uint32_t speed = 500000; // Note: Can go up to 50 MHz
static uint16_t delay;

// SPI read/write buffers for each device.
uint8_t tx_10[BYTES_PER_SPI_TRANSFER];
uint8_t rx_10[BYTES_PER_SPI_TRANSFER];
uint8_t tx_20[BYTES_PER_SPI_TRANSFER];
uint8_t rx_20[BYTES_PER_SPI_TRANSFER];

struct spi_ioc_transfer tr_10;
struct spi_ioc_transfer tr_20;

typedef enum device_names { device1_0, device2_0 } device;

// File descriptors for SPI ports.
int spi10_fd;
int spi20_fd;

//////////////////////////////////////////////

//////////////////////////////////////////////
// SPI Functions
//////////////////////////////////////////////

// Abort function.
static void pabort(const char *s)
{
  perror(s);
  abort();
}

// Exports GPIO pins (see above).
// Code adapted from: https://learnbuildshare.wordpress.com/2013/05/29/beaglebone-black-digital-ouput/
// (That's not a typo at the end of the URL.)
void export_gpio_pins() {
  /////////////////
  // Reset pin
  /////////////////
  sprintf(GPIOString, "%d", rst_pin);
  sprintf(GPIOValue, "/sys/class/gpio/gpio%d/value", rst_pin);
  sprintf(GPIODirection, "/sys/class/gpio/gpio%d/direction", rst_pin);
  
  // Export the pin
  if ((rstHandle = fopen("/sys/class/gpio/export", "ab")) == NULL){
    printf("Unable to export rst_pin %d.\n", rst_pin);
    return;
  }
 
  strcpy(getOrSetValue, GPIOString);
  fwrite(&getOrSetValue, sizeof(char), 2, rstHandle);
  fclose(rstHandle);

  // Set direction of the pin to an output
  if ((rstHandle = fopen(GPIODirection, "rb+")) == NULL){
    printf("Unable to open direction handle\n");
    return;
  }
  strcpy(getOrSetValue,"out");
  fwrite(&getOrSetValue, sizeof(char), 3, rstHandle);
  fclose(rstHandle);

  // Set output to high
  if ((rstHandle = fopen(GPIOValue, "rb+")) == NULL){
    printf("Unable to open value handle\n");
    return;
  }
  strcpy(getOrSetValue, "1"); // Set value high
  fwrite(&getOrSetValue, sizeof(char), 1, rstHandle);
  fclose(rstHandle);

  /////////////////
  // rdy0 pin
  /////////////////
  sprintf(GPIOString, "%d", rdy0_pin);
  sprintf(GPIOValue, "/sys/class/gpio/gpio%d/value", rdy0_pin);
  sprintf(GPIODirection, "/sys/class/gpio/gpio%d/direction", rdy0_pin);
  
  // Export the pin
  if ((rdy0Handle = fopen("/sys/class/gpio/export", "ab")) == NULL){
    printf("Unable to export rdy0_pin %d.\n", rdy0_pin);
    return;
  }
 
  strcpy(getOrSetValue, GPIOString);
  fwrite(&getOrSetValue, sizeof(char), 2, rdy0Handle);
  fclose(rdy0Handle);

  // Set direction of the pin to an input
  if ((rdy0Handle = fopen(GPIODirection, "rb+")) == NULL){
    printf("Unable to open direction handle\n");
    return;
  }
  strcpy(getOrSetValue,"in");
  fwrite(&getOrSetValue, sizeof(char), 2, rdy0Handle);
  fclose(rdy0Handle);

  /////////////////
  // rdy1 pin
  /////////////////
  sprintf(GPIOString, "%d", rdy1_pin);
  sprintf(GPIOValue, "/sys/class/gpio/gpio%d/value", rdy1_pin);
  sprintf(GPIODirection, "/sys/class/gpio/gpio%d/direction", rdy1_pin);
  
  // Export the pin
  if ((rdy1Handle = fopen("/sys/class/gpio/export", "ab")) == NULL){
    printf("Unable to export rdy1_pin %d.\n", rdy1_pin);
    return;
  }
 
  strcpy(getOrSetValue, GPIOString);
  fwrite(&getOrSetValue, sizeof(char), 2, rdy1Handle);
  fclose(rdy1Handle);

  // Set direction of the pin to an input
  if ((rdy1Handle = fopen(GPIODirection, "rb+")) == NULL){
    printf("Unable to open direction handle\n");
    return;
  }
  strcpy(getOrSetValue,"in");
  fwrite(&getOrSetValue, sizeof(char), 2, rdy1Handle);
  fclose(rdy1Handle);
}

// Call when done with this library.
void unexport_gpio_pins() {
  // Unexport the rst pin
  if ((rstHandle = fopen("/sys/class/gpio/unexport", "ab")) == NULL) {
    printf("Unable to unexport rst_pin\n");
    return;
  }
  sprintf(GPIOString, "%d", rst_pin);

  strcpy(getOrSetValue, GPIOString);
  fwrite(&getOrSetValue, sizeof(char), 2, rstHandle);
  fclose(rstHandle);

  // Unexport the rdy0 pin
  if ((rdy0Handle = fopen("/sys/class/gpio/unexport", "ab")) == NULL) {
    printf("Unable to unexport rst_pin\n");
    return;
  }
  sprintf(GPIOString, "%d", rdy0_pin);

  strcpy(getOrSetValue, GPIOString);
  fwrite(&getOrSetValue, sizeof(char), 2, rdy0Handle);
  fclose(rdy0Handle);

  // Unexport the rdy1 pin
  if ((rdy1Handle = fopen("/sys/class/gpio/unexport", "ab")) == NULL) {
    printf("Unable to unexport rst_pin\n");
    return;
  }
  sprintf(GPIOString, "%d", rdy1_pin);

  strcpy(getOrSetValue, GPIOString);
  fwrite(&getOrSetValue, sizeof(char), 2, rdy1Handle);
  fclose(rdy1Handle);
};

// Initializes spidev1.0 and spidev2.0.
// Returns 1 upon success, 0 upon failure.
int initialize_spi_drivers() {  
  int ret = 0;
  
  // Read and write mode.
  spi10_fd = open(device1, O_RDWR);
  if (spi10_fd < 0) {
    pabort("Can't open /dev/spidev1.0.\n");
    return 0;
  }

  spi20_fd = open(device2, O_RDWR);
  if (spi20_fd < 0) {
    pabort("Can't open /dev/spidev2.0.\n");
    return 0;
  }

  // Get and set SPI read/write modes.
  ret = ioctl(spi10_fd, SPI_IOC_WR_MODE, &mode);
  if (ret == -1) {
    pabort("Can't set SPI mode for /dev/spidev1.0.\n");
    return 0;
  }

  ret = ioctl(spi10_fd, SPI_IOC_RD_MODE, &mode);
  if (ret == -1) {
    pabort("Can't get SPI mode for /dev/spidev1.0.\n");
    return 0;
  }

  ret = ioctl(spi20_fd, SPI_IOC_WR_MODE, &mode);
  if (ret == -1) {
    pabort("Can't set SPI mode for /dev/spidev2.0.\n");
    return 0;
  }

  ret = ioctl(spi20_fd, SPI_IOC_RD_MODE, &mode);
  if (ret == -1) {
    pabort("Can't get SPI mode for /dev/spidev2.0.\n");
    return 0;
  }

  // Bits per word. 
  ret = ioctl(spi10_fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
  if (ret == -1) {
    pabort("/dev/spidev1.0: Can't set bits per word write.\n");
    return 0;
  }

  ret = ioctl(spi10_fd, SPI_IOC_RD_BITS_PER_WORD, &bits);
  if (ret == -1) {
    pabort("/dev/spidev1.0: Can't set bits per word read.\n");
    return 0;
  }

  ret = ioctl(spi20_fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
  if (ret == -1) {
    pabort("/dev/spidev2.0: Can't set bits per word write.\n");
    return 0;
  }

  ret = ioctl(spi20_fd, SPI_IOC_RD_BITS_PER_WORD, &bits);
  if (ret == -1) {
    pabort("/dev/spidev2.0: Can't set bits per word write.\n");
    return 0;
  }

  // SCLK speed.
  ret = ioctl(spi10_fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
  if (ret == -1) {
    pabort("/dev/spidev1.0: Can't set write speed.");
    return 0;
  }

  ret = ioctl(spi10_fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
  if (ret == -1) {
    pabort("/dev/spidev1.0: Can't set read speed.");
    return 0;
  }

  ret = ioctl(spi20_fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
  if (ret == -1) {
    pabort("/dev/spidev2.0: Can't set write speed.");
    return 0;
  }

  ret = ioctl(spi20_fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
  if (ret == -1) {
    pabort("/dev/spidev2.0: Can't set read speed.");
    return 0;
  } 

  tr_10.tx_buf = (unsigned long) tx_10;
  tr_10.rx_buf = (unsigned long) rx_20;
  tr_10.len = BYTES_PER_SPI_TRANSFER;
  tr_10.delay_usecs = delay;
  tr_10.speed_hz = speed;
  tr_10.bits_per_word = bits;
  
  tr_20.tx_buf = (unsigned long) tx_20;
  tr_20.rx_buf = (unsigned long) rx_20;
  tr_20.len = BYTES_PER_SPI_TRANSFER;
  tr_20.delay_usecs = delay;
  tr_20.speed_hz = speed;
  tr_20.bits_per_word = bits;

  // Now, we set up the GPIO pins.
  export_gpio_pins();

  return 1;
}

// Zeroes out the SPI write buffers.
int clean_write_buffer(device d) {
  int i;
  if (d == device1_0) {
    for (i = 0; i < BYTES_PER_SPI_TRANSFER; i++) {
      tx_10[i] = 0x0;
    }
  }
  else if (d == device2_0) {
    for (i = 0; i < BYTES_PER_SPI_TRANSFER; i++) {
      tx_20[i] = 0x0;
    }
  }
  else {
    // Unknown device.
    return 0; 
  }
  
  return 1;
}

int transfer_and_receive(device d) {
  // Before we transfer, make sure the RDY pin is low!

  if (d == device1_0) {
    sprintf(GPIOValue, "/sys/class/gpio/gpio%d/value", rdy0_pin);
    printf("Waiting for RDY to go high.\n");
    
    do {
      if ((rdy0Handle = fopen(GPIOValue, "rb+")) == NULL){
	printf("Unable to open value handle\n");
	return;
      }
      fread(&getOrSetValue, sizeof(char), 0, rdy0Handle);
      fclose(rdy0Handle);
    } while (getOrSetValue == 0);

  }
  else if (d == device2_0) {
    sprintf(GPIOValue, "/sys/class/gpio/gpio%d/value", rdy1_pin);
    printf("Waiting for RDY to go high.\n");
    do {
      if ((rdy1Handle = fopen(GPIOValue, "rb+")) == NULL){
	printf("Unable to open value handle\n");
	return;
      }
      fread(&getOrSetValue, sizeof(char), 0, rdy1Handle);
      fclose(rdy1Handle);
    } while (getOrSetValue == 0);
  }
  else {
    return -1;
  }
  
  printf("RDY is high now.\n");
  int ret;

  if (d == device1_0) {
    ret = ioctl(spi10_fd, SPI_IOC_MESSAGE(1), &tr_10);
    if (ret < 1) {
      pabort("Device 1.0: Failed to transfer/receive.\n");
      return -1;
    }
  }
  else if (d == device2_0) {
    ret = ioctl(spi20_fd, SPI_IOC_MESSAGE(1), &tr_20);
    if (ret < 1) {
      pabort("Device 2.0: Failed to transfer/receive.\n");
      return -1;
    }
  }
  else {
    // Unknown device.
    return -1;
  }
}

// Populates write buffer with a specified command.
// 10 data bits can be provided to program the wiper databits.
int ready_command(device d, int command, int databits) {
  uint8_t upper_byte;
  uint8_t lower_byte;
  switch (command) {
  case NOP : 
    // Zero-out the buffer.
    clean_write_buffer(d);
    break;
      
  case WRITE_WIPER_POS :
    clean_write_buffer(d);
      
    // Command code.
    upper_byte = (0xFF & 0x04);

    // Upper two data bits.
    upper_byte = (upper_byte & (databits >> 6 & 0x03));

    // Lower eight data bits.
    lower_byte = (0xFF & databits);

    if (d == device1_0) {
      tx_10[1] = upper_byte;
      tx_10[0] = lower_byte;
    }
    else if (d == device2_0) {
      tx_20[1] = upper_byte;
      tx_20[0] = lower_byte;
    }
    else {
      return 0;
    }

    break;

  case READ_WIPER_POS : 
    clean_write_buffer(d);
    
    // Command code.
    upper_byte = (0xFF & 0x08);

    if (d == device1_0) {
      tx_10[1] = upper_byte;
    }
    else if (d == device2_0) {
      tx_20[1] = upper_byte;
    }
    else {
      return 0;
    }
    
    break;

 case RESET_TO_MIDSCALE: 
   clean_write_buffer(d);
    
   // Command code.
   upper_byte = (0xFF & 0x10);

   if (d == device1_0) {
     tx_10[1] = upper_byte;
   }
   else if (d == device2_0) {
     tx_20[1] = upper_byte;
   }
   else {
     return 0;
   }
    
   break;

 case ENABLE_WRITE: 
   clean_write_buffer(d);
    
   // Command code.
   upper_byte = (0xFF & 0x18);

   // Set D2 (C2) to be 0 (resistor performance mode).
   // Set D1 (C1) to be 1 (allows update of wiper databits through digital interface).
   lower_byte = (0xFF & 0x02);

   if (d == device1_0) {
     tx_10[1] = upper_byte;
     tx_10[0] = lower_byte;
   }
   else if (d == device2_0) {
     tx_20[1] = upper_byte;
     tx_20[0] = lower_byte;
   }
   else {
     return 0;
   }
    
   break;

 case READ_CONTROL_REG: 
   clean_write_buffer(d);
    
   // Command code.
   upper_byte = (0xFF & 0x1c);

   if (d == device1_0) {
     tx_10[1] = upper_byte;
   }
   else if (d == device2_0) {
     tx_20[1] = upper_byte;
   }
   else {
     return 0;
   }
    
   break;

 case SHUTDOWN_DEVICE: 
   clean_write_buffer(d);
    
   // Command code.
   upper_byte = (0xFF & 0x40);

   // D0 = 0 is normal mode, D0 = 1 shuts down the device.
   lower_byte = (0x01 & databits);

   if (d == device1_0) {
     tx_10[1] = upper_byte;
     tx_10[0] = lower_byte;
   }
   else if (d == device2_0) {
     tx_20[1] = upper_byte;
     tx_10[0] = lower_byte;
   }
   else {
     return 0;
   }
   
   break;

  }
  
  return 1;
}
