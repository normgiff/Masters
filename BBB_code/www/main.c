#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include "spi_lib.h"
#include "uart_lib.h"

// Locations range between columns A through N, rows 1 through 13.  
// Includes null character.
#define LOCATION_SIZE ((3 + 1) * sizeof(char))
#define BIT_SIZE ((1 + 1) * sizeof(char))
#define ZIF_ROWS 13
#define ZIF_COLS 13

// ZIF mapping.
// Row mapping (index to row): 0->A, 1->B, ... 12->N
// Column mapping (index to col): 0->1, 1->2, ... 12->13
int ZIF[ZIF_ROWS][ZIF_COLS] = {17, 18, 19, 20, 21, 22, 1, 2, 3, 4, 5, 6, 169, 
                               23, 24, 25, 26, 27, 28, 7, 8, 9, 10, 11, 12, 168, 
                               80, 75, 29, 30, 31, 32, 13, 14, 15, 16, 55, 60, 167, 
                               79, 74, 70, 129, 128, 96, 50, 49, 127, 51, 56, 61, 166, 
                               78, 73, 69, 135, 134, 133, 132, 131, 130, 52, 57, 62, 165, 
                               77, 72, 68, 66, 140, 139, 138, 137, 136, 53, 58, 63, 164, 
                               76, 71, 67, 65, 145, 144, 143, 142, 141, 54, 59, 64, 163, 
                               84, 88, 91, 93, 150, 149, 148, 147, 146, 41, 37, 33, 162, 
                               83, 87, 90, 156, 155, 154, 153, 152, 151, 42, 38, 34, 161, 
                               82, 86, 89, 92, 94, 95, 48, 47, 45, 43, 39, 35, 160, 
                               81, 85, 112, 111, 110, 109, 126, 125, 46, 44, 40, 36, 159, 
                               108, 107, 106, 105, 104, 103, 124, 123, 122, 121, 120, 119, 158, 
                               102, 101, 100, 99, 98, 97, 118, 117, 116, 115, 114, 113, 157};

/*
 * Removes all instances of character c from a string str.
 */
void remove_char(char *str, char c) {
  char *src, *dst;

  for (src = dst = str; *src != '\0'; src++) {
    *dst = *src;
    if (*dst != c) { 
      dst++;
    }
  }
  
  *dst = '\0';
}

/*
 * Removes [ and ] from [token1, token2, ...] json-encoded data.
 */
void trim_brackets(char* arr) {
  remove_char(arr, '[');
  remove_char(arr, ']');
}

// Inputs: arr_len, names, locations_in, ffs_in, directions_in, cycles_in.
// Outputs: locations_out, ffs_out, directions_out, cycles_out. 
// Note that this function allocates memory for the output arrays. 
void process_template(int    arr_len, 
		      char*  names, 
		      char*  locations_in, 
		      char*  ffs_in, 
		      char*  directions_in, 
		      char*  cycles_in, 
		      char** locations_out, 
		      char** ffs_out, 
		      char** directions_out, 
		      char** cycles_out) {

  // Inputs arrive as "[token1, token2, ...]"
  const char s[2] = ",";
  char *token;
  int index;

  // Remove brackets from strings.
  trim_brackets(names);
  trim_brackets(locations_in);
  trim_brackets(ffs_in);
  trim_brackets(directions_in);
  trim_brackets(cycles_in);

  // If no data, just set all output buffers to NULL.
  if (arr_len == 0) {
    locations_out = NULL;
    ffs_out = NULL;
    directions_out = NULL;
    cycles_out = NULL;
    return;
  }

  // Pin locations.
  locations_out = (char**) calloc(arr_len, LOCATION_SIZE);
  assert(locations_out != NULL);

  token = strtok(locations_in, s);

  index = 0;
  while(token != NULL && strcmp(token, "null") != 0) {
    locations_out[index] = token;
    index += LOCATION_SIZE;

    token = strtok(NULL, s);
  }

  // Force-formats.
  ffs_out = (char**) calloc(arr_len, BIT_SIZE);
  assert(ffs_out != NULL);

  token = strtok(ffs_in, s);

  index = 0;
  while(token != NULL && strcmp(token, "null") != 0) {
    ffs_out[index] = token;
    index += BIT_SIZE;

    token = strtok(NULL, s);
  }

  // Pin directions.
  directions_out = (char**) calloc(arr_len, BIT_SIZE);
  assert(directions_out != NULL);

  token = strtok(directions_in, s);

  index = 0;
  while(token != NULL && strcmp(token, "null") != 0) {
    ffs_out[index] = token;
    index += BIT_SIZE;

    token = strtok(NULL, s);
  }

  // Test cycles.
  cycles_out = (char**) calloc(arr_len, BIT_SIZE);
  assert(cycles_out != NULL);

  token = strtok(cycles_in, s);
  index = 0;
  while(token != NULL && strcmp(token, "null") != 0) {
    cycles_out[index] = token;
    index += BIT_SIZE;

    token = strtok(NULL, s);
  }
}

// Converts the arrays from the web form into 16-byte arrays for UART.
void convert_to_bytes(int len, 
		      char** locations_in,
		      char** ffs_in, 
		      char** directions_in, 
		      char** cycles_in,
		      char** ffs_out, 
		      char** directions_out, 
		      char** cycles_out
		      )
{
  // Notes: 
  // 1) locations_in will look like [A1, B1, ...], depending on the user input. 
  //    That is a C array, not a json-encoded array.
  //    Likewise for the other types of input arrays, e.g. ffs_in.
  // 2) If you look at the Verilog (see UART_CTRL.v), you can get a sense of the 
  //    BBB-FPGA communication protocol. Also have a look at uart_lib.h, which 
  //    abstracts the protocol. 
  // 3) Basically, you will want to create an array of 16 bytes (I am using char, 
  //    uint8_t would have been a better choice but oh well) like follows: 
  //    [{template bit 1} {template bit 0} {data for ZIF pin 125} {data for ZIF pin 125} ... {data for ZIF pin 0}]
  //    Once you set up the appropriate array, call the appropriate method in uart_lib.h.
  // 4) NOTE: Notice that there is no locations_out array. The locations_in array is used for indexing into the ffs, directions, 
  //          and cycles arrays. Example: In the ZIF table near the top of this file, 
  //          A1 maps to index 16 (17 - 1, since the table above is one-indexed).
  // 
  // Say the web form input is as follows (if I'm testing the inverter on the MOSIS demo chip): 
  // * One template (01), consisting of two pins: (C1, input) and (D2, output). Leading edge 2 is used for C1.
  // * One test vector, using template 01, assigns 1 to C1 with force-format DNRZ_L and expects D2 = 0. 
  // 
  // First, the output vector needs to be stored somewhere. I don't think the web form (results.php) takes care of that yet, so 
  // be sure to handle that at some point.
  // Next, notice that using the table near the top of this file, C1 maps to index 19 - 1 = 18 and D2 maps to index 24 - 1 = 23.
  // So, we create arrays as follows: 
  // ffs_out: [All zeroes, but index 18 is set to 1, not 0, since that corresponds to DNRZ_L.]
  // directions_out: [All ones (NOT zeroes), but index 18 is set to 0 since that index maps to an input pin.]
  // cycles_out: [All zeroes, but index 18 is set to 1 since that index maps to leading edge 2 associated with pin C1.]
  //
  // Let me know if you have any questions.

  // TODO  
}

int main(int argc, char *argv[])
{
  int len;

  // Signal names.
  // NOTE: For now, these are not used. 
  // In the future, they should be used to help users understand their test results.
  //char **t1_sig_names;
  //char **t2_sig_names;
  //char **t3_sig_names;
  //char **t4_sig_names;

  // Signal locations.
  char** t1_sig_locs = NULL;
  char** t2_sig_locs = NULL;
  char** t3_sig_locs = NULL;
  char** t4_sig_locs = NULL;

  // Force formats.
  char** t1_ffs = NULL;
  char** t2_ffs = NULL;
  char** t3_ffs = NULL;
  char** t4_ffs = NULL;

  // Pin directions.
  char** t1_dirs = NULL;
  char** t2_dirs = NULL;
  char** t3_dirs = NULL;
  char** t4_dirs = NULL;

  // Test cycles (for each pin).
  char** t1_cycles = NULL;
  char** t2_cycles = NULL;
  char** t3_cycles = NULL;
  char** t4_cycles = NULL;

  // Template 1.
  len = atoi(argv[1]);
  process_template(len, 
		   argv[2],
		   argv[3],
		   argv[4],
		   argv[5],
		   argv[6],
		   t1_sig_locs,
		   t1_ffs,
		   t1_dirs,
		   t1_cycles);

  // Template 2.
  len = atoi(argv[7]);
  process_template(len, 
		   argv[8],
		   argv[9],
		   argv[10],
		   argv[11],
		   argv[12],
		   t2_sig_locs,
		   t2_ffs,
		   t2_dirs,
		   t2_cycles);

  // Template 3.
  len = atoi(argv[13]);
  process_template(len, 
		   argv[14],
		   argv[15],
		   argv[16],
		   argv[17],
		   argv[18],
		   t3_sig_locs,
		   t3_ffs,
		   t3_dirs,
		   t3_cycles);

  // Template 4.
  len = atoi(argv[19]);
  process_template(len, 
		   argv[20],
		   argv[21],
		   argv[22],
		   argv[23],
		   argv[24],
		   t4_sig_locs,
		   t4_ffs,
		   t4_dirs,
		   t4_cycles);

  // Convert each bit-vector (ffs, dirs, cycles) into 16 bytes, then use appropriate
  // uart_lib.h command.
  // TODO

  // Then, accumulate input vectors and transfer them to FPGA.
  // TODO

  // Finally, execute tests.
  // TODO

  // Request as many output vectors as input vectors, then make comparisons.

  return 0;
}
