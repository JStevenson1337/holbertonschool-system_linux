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


/**
 * struct file_s - singly linked list
 * @str: variable
 * @size: variable
 * @time: variable
 * @next: points to the next node
 * @prev: points to the prev node
 * @var: environment variables.
 * Description: singly linked list node to store the env
 */
typedef struct file_s
{
	char *var;
	long int size;
	unsigned long int time;
	struct file_s *prev;
	struct file_s *next;
} file_s;

char *validate_file_s(const char *dirname, const char *filename);
char *validate_args(char **argv, char **errors);
char **validate_dir(int argc, char **argv, int *ret, int *fcount, int *ecount, int *ficount, char *args);
void error_handler(int err, const char *dirname, const char *progname);
void listFiles(const char *dirname);
void error_handler(int error, const char *path, const char *filename);
int _strcmp(char *s1, char *s2);

void print_list_normalized(const char *dirname);
void print_list_1_by_1(const char *dirname);
void print_list_rev(const char *dirname);
void print_list_time(const char *dirname);
void print_list_size(const char *dirname);

struct stat get_stat(const char *path);


#endif /*_HLS_H*/
