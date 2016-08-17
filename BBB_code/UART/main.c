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

#define MODEMDEVICE "/dev/ttyO1"

#define _POSIX_SOURCE 1 

#define FALSE 0
#define TRUE 1

#define BYTES_PER_TRANSFER 16

///////////////////////////////

int main()
{
  int fd, c, res;
  struct termios oldtio, newtio;

  int input_buf_1;
  int input_buf_2;

  char UART_READ_BUF[16];
  char UART_WRITE_BUF[16];
  int i;
  
  // Zero out the UART read and write buffers.
  for (i = 0; i < 16; i++) {
    UART_READ_BUF[i] = 0x00;
    UART_WRITE_BUF[i] = 0x00;
  }
  
  fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY );
  if (fd < 0) { perror(MODEMDEVICE); exit(-1); }
  bzero(&newtio, sizeof(newtio));
  newtio.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
  newtio.c_iflag = IGNPAR;
  newtio.c_oflag = 0;

  // Read when 16 bytes have been received.
  newtio.c_cc[VMIN] = 16;

  tcflush(fd, TCIFLUSH);
  tcsetattr(fd,TCSANOW,&newtio);

  while (TRUE) {

    printf("Which command do you want to send to the FPGA?\n");
    printf("1: Send template vector.\n");
    printf("2: Send FF vector.\n");
    printf("3: Send cycle vector.\n");
    printf("4: Send input vector.\n");
    printf("5: Send cycle configuration data.\n");
    printf("6: Execute tests.\n");
    printf("7: Send back data.\n");

    gets((char *) &input_buf_1);

    input_buf_1 -= 48;

    if (input_buf_1 == 1) {
      UART_WRITE_BUF[0] = TEMPLATE_HDR; 
    }
    else if (input_buf_1 == 2) {
      UART_WRITE_BUF[0] = FF_HDR; 
    }
    else if (input_buf_1 == 3) {
      UART_WRITE_BUF[0] = CYCLE_HDR; 
    }
    else if (input_buf_1 == 4) {
      UART_WRITE_BUF[0] = INPUT_HDR; 
    }
    else if (input_buf_1 == 5) {
      UART_WRITE_BUF[0] = CYCLE_CONFIG_HDR; 
      printf("Please enter cycle configuration bytes.\n");
      printf("Leading edge 1: ");
      res = scanf("%2x", &input_buf_2);
      if (res == EOF) {
	  input_buf_2 = 0x00;
      }
      UART_WRITE_BUF[1] = input_buf_2;	
      printf("Leading edge 2: ");
      res = scanf("%2x", &input_buf_2);
      if (res == EOF) {
	input_buf_2 = 0x00;
      }
      UART_WRITE_BUF[2] = input_buf_2;	
      printf("Trailing edge: ");
      res = scanf("%2x", &input_buf_2);
      if (res == EOF) {
	input_buf_2 = 0x00;
      }
      UART_WRITE_BUF[3] = input_buf_2;	
      printf("Cycle length: ");
      res = scanf("%2x", &input_buf_2);
      if (res == EOF) {
	input_buf_2 = 0x00;
      }
      UART_WRITE_BUF[4] = input_buf_2;	 
      getchar();
    }
    else if (input_buf_1 == 6) {
      UART_WRITE_BUF[0] = EXECUTE_TESTS; 
    }
    else if (input_buf_1 == 7) {
      UART_WRITE_BUF[0] = SEND_BACK_DATA; 
    }
    else {
      printf("Invalid command: %d\n", input_buf_1);
      printf("Exiting.\n");
      return -1;
    }

    write(fd, UART_WRITE_BUF, 16);

    res = read(fd, &UART_READ_BUF, 16);

    if (input_buf_1 != 7) {
      if (UART_READ_BUF[0] == ACKNOWLEDGE) {
	if (input_buf_1 == 1) {
	  printf("Please enter template vector bytes.\n");
	}
	else if (input_buf_1 == 2) {
	  printf("Please enter FF vector bytes.\n");
	}
	else if (input_buf_1 == 3) {
	  printf("Please enter cycle vector bytes.\n");
	}
	else if (input_buf_1 == 4) {
	  printf("Please enter input vector bytes.\n");
	}      
	else if (input_buf_1 == 6){
	  printf("Tests completed.\n");
	  continue;
	}

	if (input_buf_1 <= 4) {
	  for (i = 0; i < 16; i++) {
	    printf("Byte %d: ", i);
	    res = scanf("%2x", &input_buf_2);
	    if (res == EOF) {
	      printf("\n");
	    }
	    UART_WRITE_BUF[i] = input_buf_2;	
	  }
	}
	printf("Send these bytes? If yes, press any key. If no, press CTRL + C.\n");
	for (i = 0; i < 16; i++) {
	  printf("Byte %d: %2x\n", i, UART_WRITE_BUF[i]);
	}

	getchar();

	write(fd, UART_WRITE_BUF, 16);

	res = read(fd, &UART_READ_BUF, 16);

	if (UART_READ_BUF[0] == ACKNOWLEDGE) {
	  printf("Vector retrieved successfully.\n");
	}
	else {
	  printf("FPGA failed to acknowledge transmission. Please investigate.\n");
	  return -1;
	}
      }
      else {
	if (UART_READ_BUF[0] == NO_INPUT_VECTORS) {
	  printf("FPGA reported no input vectors to test. Exiting.\n");
	  return -1;
	}
	else if (UART_READ_BUF[0] == UNKNOWN_COMMAND) {
	  printf("FPGA failed to recognize command sent to it. Please investigate.\n");
	  return -1;
	}
      }
    }
    else {
      printf("Data bytes retrieved: \n");
      for (i = 0; i < 16; i++) {
	printf("Byte %d: %2x\n", i, UART_READ_BUF[i]);
      }
    }

  }

  tcsetattr(fd, TCSANOW, &oldtio);

  return 0;
}
