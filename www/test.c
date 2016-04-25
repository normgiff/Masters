#include <stdio.h>


void rem_char(char *str, char c) {

    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != c) dst++;
    }
    *dst = '\0';
}



int main(int argc, char *argv[])
{
	const char s[2] = ",";
	char *token;
	rem_char(argv[1], '[');
	rem_char(argv[1], ']');
	token = strtok(argv[1], s);
	printf("Inside the main c program\n");
	printf("The number of arguments: %i\n", argc);
	printf("The number of strings in an array are: %s\n", argv[2]);
	
	
	while( token != NULL ) 
   {
      printf( " %s\n", token );
    
      token = strtok(NULL, s);
   }
	
	return 0;





}

