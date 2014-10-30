#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "echo-1.h"

#define	ESC		27


int main (int argc, char *argv[]) {
	char c;
	char		input_buffer[INPUT_BUFFER_SIZE],*i;

	printf("\n **** echo-1  ver 0.0.1 active\n\n");
	printf("enter >");

	i = input_buffer;
	/* use system call to make terminal send all keystrokes directly to stdin */
	system ("/bin/stty raw");

	while((c=getchar()!= ESC)) {
	  /* type a period to break out of the loop, since CTRL-D won't work raw */
	  *i++=c;

	}
	*i = '\0';
	printf("\n<%s>",input_buffer);
	/* use system call to set terminal behavior to more normal behavior */
	system ("/bin/stty cooked");
	printf("\n\nnormal termination\n");
    return 0;
}
