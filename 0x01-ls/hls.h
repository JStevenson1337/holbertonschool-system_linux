#ifndef _HLS_H
#define _HLS_H

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define current_directory "."
#define parent_directory ".."

void listFiles(const char *dirname);
void error_handler(int error, const char *path, const char *filename);
int _strcmp(char *s1, char *s2);

void print_list_normalized(const char *dirname);
void print_list_1_by_1(const char *dirname);
void print_list_rev(const char *dirname);
void print_list_time(const char *dirname);
void print_list_size(const char *dirname);


int set_flags(const char **flag);

#endif /*_HLS_H*/
