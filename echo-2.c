/*
 * echo-2.c
 *
 *  Created on: Nov 12, 2014
 *      Author: mam1
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BAUDRATE B9600
#define MODEMDEVICE "/dev/ttyO1" 	//Beaglebone Black serial port
#define _POSIX_SOURCE 1 			//POSIX compliant source */
#define FALSE 0
#define TRUE 1

int s_open(void);
void s_close(int);

int main(void)
{
    int fd, c;
    char in_buf[255], out_buf[255], *in_ptr, *out_ptr;

    fd = s_open();
    printf("s_open returned,<%d>\n",fd);
    /***********************************************************************************************/
    out_ptr = out_buf;
    bzero(out_buf, sizeof(out_buf)); /* clear buffer */
    *out_ptr++ = 'h';
    *out_ptr++ = 'i';
    *out_ptr++ = ' ';
    *out_ptr++ = 'y';
    *out_ptr++ = 'o';
    *out_ptr++ = 'u';
    *out_ptr++ = '\n';
    *out_ptr = 27;

    printf("out_buf size  = %d\n",sizeof(out_buf));
    printf("string length = %d\n",strlen(out_buf));
    write(fd, out_buf, strlen(out_buf));

    while (c != 'q') {

        if (read(fd,&c,1)>0) write(STDOUT_FILENO,&c,1); // if new data is available on the serial port, print it out
        if (read(STDIN_FILENO,&c,1)>0) write(fd,&c,1); // if new data is available on the console, send it to the serial port

    }
    s_close(fd);
    return 0;
}

