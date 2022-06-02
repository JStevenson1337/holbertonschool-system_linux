#ifndef GETLINE_H
#define GETLINE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define READ_SIZE 1024

typedef struct readline_s
{
	char fd;
	char *line;
	ssize_t size;
	struct readline_s *next;
} readline_t;

char *another_one(readline_t *curr);
char *_getline(const int fd);


#endif /* GETLINE_H */
