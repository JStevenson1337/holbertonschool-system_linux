#ifndef GETLINE_H
#define GETLINE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define READ_SIZE 1024

/**
	* struct reader_s - struct that holds a file descriptor and a buffer
	* @fd: file descriptor
	* @buf: buffer
	* @bytes: number of bytes in buffer
	* @next: pointer to next reader struct
	**/
typedef struct reader_s
{
	int fd;
	char *buf;
	int bytes;
	struct reader_s *next;
} reader_t;

char *_getline(const int fd);


#endif /* GETLINE_H */
