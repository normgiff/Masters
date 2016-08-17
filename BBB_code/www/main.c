#include <assert.h>
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
int ZIF[ZIF_COLS][ZIF_ROWS] = {0}; // TODO

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
 * Removes [ and ] from [token1, token2, ...] arrays.
 */
void trim_brackets(char* arr) {
  remove_char(arr, '[');
  remove_char(arr, ']');
}

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

void convert_to_bytes()
{
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

  return 0;
}
