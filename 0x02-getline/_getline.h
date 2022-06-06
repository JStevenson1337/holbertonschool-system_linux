#ifndef GETLINE_H
#define GETLINE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define READ_SIZE 1024


char *_getline(const int fd);
int get_fd_pos(char ***all_text_fd, int ***all_fds, char ***all_buff_fd, int *num_fds, int fd);


#endif /* GETLINE_H */
