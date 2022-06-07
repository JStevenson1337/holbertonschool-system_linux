#ifndef _getline_h
#define _getline_h

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define READ_SIZE 1024

/**
 * struct getline_s - structure for getline
 * @fd: file descriptor
 * @buf: buffer
 * @bytes:  size_t of bytes in buffer
 * @next: pointer to next struct
 **/
typedef struct getline_r
{
	int fd;
	char *buf;
	int bytes;
	struct getline_r *next;
} getline_t;

char *_getline(const int fd);
int get_fd_pos(char ***all_text_fd, int ***all_fds, char ***all_buff_fd, int *num_fds, int fd);


#endif /* _getline_h */
