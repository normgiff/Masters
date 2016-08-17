// Author: Daniel Khoury

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>
#include <string.h>

#include <stdlib.h>

////////////////////////////////
// UART Commands and Codes
////////////////////////////////

#define TEMPLATE_HDR     0x00
#define FF_HDR           0x01
#define CYCLE_HDR        0x02
#define INPUT_HDR        0x03
#define CYCLE_CONFIG_HDR 0x04
#define EXECUTE_TESTS    0x05
#define SEND_BACK_DATA   0x06

#define ACKNOWLEDGE      0x00
#define NO_INPUT_VECTORS 0x01
#define UNKNOWN_COMMAND  0xFF

///////////////////////////////

////////////////////////////////
// UART Initialization
////////////////////////////////

// NOTE: Verilog code expects 115200 baud rate.
#define BAUDRATE B115200

#define UART_DEVICE "/dev/ttyO1"

#define _POSIX_SOURCE 1 

#define FALSE 0
#define TRUE 1

#define BYTES_PER_UART_TRANSFER 16

///////////////////////////////

////////////////////////////////
// UART Data Structures
////////////////////////////////

int uart_fd;

struct termios oldtio, newtio;

// Read and write buffers.
char UART_READ_BUF[BYTES_PER_UART_TRANSFER];
char UART_WRITE_BUF[BYTES_PER_UART_TRANSFER];

///////////////////////////////

////////////////////////////////
// Functions
////////////////////////////////

// Initializes the UART_DEVICE port.
// Returns 1 upon success, 0 upon failure.
int initialize_uart() {
  
  // Zero-out the read and write buffers.
  int i;
  for (i = 0; i < BYTES_PER_UART_TRANSFER; i++) {
    UART_READ_BUF[i] = 0;
    UART_WRITE_BUF[i] = 0;
  }

  // Open the port.
  // O_RDWR: Read and write mode.
  // O_NOCTTY: CTRL-C will not close the port.
  uart_fd = open(UART_DEVICE, O_RDWR | O_NOCTTY);
  
  if (uart_fd < 0) {
    perror(UART_DEVICE);
    return 0;
  }

  // Save the current UART settings.
  tcgetattr(uart_fd, &oldtio);

  // Clear this struct for the new UART settings.
  bzero(&newtio, sizeof(newtio));

  // BAUDRATE: Bandwidth (bits per second) on the lines.
  // CS8: Word size is 8 bits.
  // CLOCAL: Local connection (not connected over a modem).
  // CREAD: Enable receiving characters.
  newtio.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;

  // No parity bit, raw input.
  newtio.c_iflag = IGNPAR;

  // Raw output.
  newtio.c_oflag = 0;

  // Block reads until 16 bytes are received.
  newtio.c_cc[VMIN] = 16;

  // Clean modem line, activate UART port settings.
  tcflush(uart_fd, TCIFLUSH);
  tcsetattr(uart_fd, TCSANOW, &newtio);

  return 1;
}

// Sends a template vector to the FPGA.
// Returns 1 if the FPGA acknowledges all requests, 0 otherwise.
int send_template_vector(char* template_vector) {

  // Inform the FPGA that we will send it a template vector.
  UART_WRITE_BUF[0] = TEMPLATE_HDR;
  write(uart_fd, UART_WRITE_BUF, BYTES_PER_UART_TRANSFER);

  // Wait for an acknowledgement.
  read(uart_fd, UART_READ_BUF, BYTES_PER_UART_TRANSFER);

  if (UART_READ_BUF[0] != ACKNOWLEDGE) {
    printf("send_template_vector: FPGA failed to acknowledge template header.\n");
    return 0;
  }
  
  // Copy the template_vector data into the write buffer.
  memcpy(UART_WRITE_BUF, template_vector, BYTES_PER_UART_TRANSFER);

  // Send the template vector.
  write(uart_fd, UART_WRITE_BUF, BYTES_PER_UART_TRANSFER);

  // Wait for an acknowledgement.
  read(uart_fd, UART_READ_BUF, BYTES_PER_UART_TRANSFER);

  if (UART_READ_BUF[0] != ACKNOWLEDGE) {
    printf("send_template_vector: FPGA failed to acknowledge template vector.\n");
    return 0;
  }

  return 1;
}

// Sends an input vector to the FPGA.
// Returns 1 if the FPGA acknowledges all requests, 0 otherwise.
int send_input_vector(char* input_vector) {

  // Inform the FPGA that we will send it an input vector.
  UART_WRITE_BUF[0] = INPUT_HDR;
  write(uart_fd, UART_WRITE_BUF, BYTES_PER_UART_TRANSFER);

  // Wait for an acknowledgement.
  read(uart_fd, UART_READ_BUF, BYTES_PER_UART_TRANSFER);

  if (UART_READ_BUF[0] != ACKNOWLEDGE) {
    printf("send_input_vector: FPGA failed to acknowledge input header.\n");
    return 0;
  }
  
  // Copy the input_vector data into the write buffer.
  memcpy(UART_WRITE_BUF, input_vector, BYTES_PER_UART_TRANSFER);

  // Send the template vector.
  write(uart_fd, UART_WRITE_BUF, BYTES_PER_UART_TRANSFER);

  // Wait for an acknowledgement.
  read(uart_fd, UART_READ_BUF, BYTES_PER_UART_TRANSFER);

  if (UART_READ_BUF[0] != ACKNOWLEDGE) {
    printf("send_input_vector: FPGA failed to acknowledge input vector.\n");
    return 0;
  }

  return 1;
}

// Sends a cycle vector to the FPGA.
// Returns 1 if the FPGA acknowledges all requests, 0 otherwise.
int send_cycle_vector(char* cycle_vector) {

  // Inform the FPGA that we will send it a cycle vector.
  UART_WRITE_BUF[0] = CYCLE_HDR;
  write(uart_fd, UART_WRITE_BUF, BYTES_PER_UART_TRANSFER);

  // Wait for an acknowledgement.
  read(uart_fd, UART_READ_BUF, BYTES_PER_UART_TRANSFER);

  if (UART_READ_BUF[0] != ACKNOWLEDGE) {
    printf("send_cycle_vector: FPGA failed to acknowledge cycle header.\n");
    return 0;
  }
  
  // Copy the input_vector data into the write buffer.
  memcpy(UART_WRITE_BUF, cycle_vector, BYTES_PER_UART_TRANSFER);

  // Send the cycle vector.
  write(uart_fd, UART_WRITE_BUF, BYTES_PER_UART_TRANSFER);

  // Wait for an acknowledgement.
  read(uart_fd, UART_READ_BUF, BYTES_PER_UART_TRANSFER);

  if (UART_READ_BUF[0] != ACKNOWLEDGE) {
    printf("send_cycle_vector: FPGA failed to acknowledge cycle vector.\n");
    return 0;
  }

  return 1;
}

// Sends a force-format vector to the FPGA.
// Returns 1 if the FPGA acknowledges all requests, 0 otherwise.
int send_ff_vector(char* ff_vector) {

  // Inform the FPGA that we will send it a force-format vector.
  UART_WRITE_BUF[0] = FF_HDR;
  write(uart_fd, UART_WRITE_BUF, BYTES_PER_UART_TRANSFER);

  // Wait for an acknowledgement.
  read(uart_fd, UART_READ_BUF, BYTES_PER_UART_TRANSFER);

  if (UART_READ_BUF[0] != ACKNOWLEDGE) {
    printf("send_ff_vector: FPGA failed to acknowledge force-format header.\n");
    return 0;
  }
  
  // Copy the ff_vector data into the write buffer.
  memcpy(UART_WRITE_BUF, ff_vector, BYTES_PER_UART_TRANSFER);

  // Send the force-format vector.
  write(uart_fd, UART_WRITE_BUF, BYTES_PER_UART_TRANSFER);
 
  // Wait for an acknowledgement.
  read(uart_fd, UART_READ_BUF, BYTES_PER_UART_TRANSFER);

  if (UART_READ_BUF[0] != ACKNOWLEDGE) {
    printf("send_ff_vector: FPGA failed to acknowledge force-format vector.\n");
    return 0;
  }

  return 1;
}

// Sends a force-format vector to the FPGA.
// Returns 1 if the FPGA acknowledges all requests, 0 otherwise.
int send_cycle_config_data(char leading_edge_1, 
			   char leading_edge_2,
			   char trailing_edge,
			   char cycle_length) {

  // Formulate the cycle configuration bit vector.
  UART_WRITE_BUF[0] = CYCLE_CONFIG_HDR;
  UART_WRITE_BUF[1] = leading_edge_1;
  UART_WRITE_BUF[2] = leading_edge_2;
  UART_WRITE_BUF[3] = trailing_edge;
  UART_WRITE_BUF[4] = cycle_length;

  // Send the cycle configuration data.
  write(uart_fd, UART_WRITE_BUF, BYTES_PER_UART_TRANSFER);
 
  // Wait for an acknowledgement.
  read(uart_fd, UART_READ_BUF, BYTES_PER_UART_TRANSFER);

  if (UART_READ_BUF[0] != ACKNOWLEDGE) {
    printf("send_cycle_config_data: FPGA failed to acknowledge cycle configuration data.\n");
    return 0;
  }

  return 1;
}

// Instructs the FPGA to execute all tests.
int execute_tests() {

  // Formulate the request.
  UART_WRITE_BUF[0] = EXECUTE_TESTS;

  // Send the cycle configuration data.
  write(uart_fd, UART_WRITE_BUF, BYTES_PER_UART_TRANSFER);
 
  // Wait for an acknowledgement.
  read(uart_fd, UART_READ_BUF, BYTES_PER_UART_TRANSFER);

  if (UART_READ_BUF[0] != ACKNOWLEDGE) {
    if (UART_READ_BUF[0] == NO_INPUT_VECTORS) {
      printf("execute_tests: FPGA reports no input vectors loaded.\n");
    }
    else {
      printf("execute_tests: FPGA failed to acknowledge request.\n");
    }
    return 0;
  }

  return 1;
}

// Instructs the FPGA to return an output vector.
// User must provide a buffer to hold the retrieved data.
// This function must be called as many times as there are output vectors.
void retrieve_data(char* data) {

  // Formulate the request.
  UART_WRITE_BUF[0] = SEND_BACK_DATA;

  // Send the request.
  write(uart_fd, UART_WRITE_BUF, BYTES_PER_UART_TRANSFER);
 
  // Wait for the data to return.
  read(uart_fd, UART_READ_BUF, BYTES_PER_UART_TRANSFER);

  memcpy(data, UART_READ_BUF, BYTES_PER_UART_TRANSFER);
}

///////////////////////////////


