#ifndef GETLINE_H
#define GETLINE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define READ_SIZE 1024


char *_getline(const int fd);

typedef struct readline_s
{
	char *line;
	size_t len;
	size_t size;
	struct readline_s *next;
} readline_t;

#endif /* GETLINE_H */
