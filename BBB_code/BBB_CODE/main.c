#include "spi_lib.h"
#include "uart_lib.h"

// Right now, let's just test the SPI driver...
int main(int argc, char* argv) {
  int ret = initialize_spi_drivers();
  if (ret == 0) {
    printf("Something went wrong when initializing SPI drivers.\n");
  }
  
  device d_10 = device1_0;
  device d_20 = device2_0;
  
  int databits = 0;
  
  ret = ready_command(d_10, RESET_TO_MIDSCALE, 0);
  if (ret == 0) {
    printf("Something went wrong when readying a command.\n");
  }

  ret = transfer_and_receive(d_10);
  if (ret == 0) {
    printf("Something went wrong when transferring/receiving.\n");
  }
  ret = ready_command(d_20, RESET_TO_MIDSCALE, 0);
  if (ret == 0) {
    printf("Something went wrong when readying a command.\n");
  }

  ret = transfer_and_receive(d_20);
  if (ret == 0) {
    printf("Something went wrong when transferring/receiving.\n");
  }

  // Done with GPIO pins.
  unexport_gpio_pins();
}
