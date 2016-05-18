#include <stdio.h>

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

int main(int argc, char *argv[])
{
  const char s[2] = ",";
  char *token;
  char **array;
  
  // Inputs arrive as [token1, token2, ...]
  remove_char(argv[1], '[');
  remove_char(argv[1], ']');
  token = strtok(argv[1], s);
  
  int i = 0;
  while( token != NULL ) 
    {
      token = strtok(NULL, s);
    }
	
  return 0;
}
