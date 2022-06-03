#ifndef _HLS_H
#define _HLS_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define PROG_NAME "hls"
#define BUF_SIZE 1024
#define STARTING_FILES_SIZE 1

#define RUSR (file->stat.st_mode & S_IRUSR ? 'r' : '-')
#define WUSR (file->stat.st_mode & S_IWUSR ? 'w' : '-')
#define XUSR (file->stat.st_mode & S_IXUSR ? 'x' : '-')
#define RGRP (file->stat.st_mode & S_IRGRP ? 'r' : '-')
#define WGRP (file->stat.st_mode & S_IWGRP ? 'w' : '-')
#define XGRP (file->stat.st_mode & S_IXGRP ? 'x' : '-')
#define ROTH (file->stat.st_mode & S_IROTH ? 'r' : '-')
#define WOTH (file->stat.st_mode & S_IWOTH ? 'w' : '-')
#define XOTH (file->stat.st_mode & S_IXOTH ? 'x' : '-')

#define cd "."
#define pd ".."


typedef struct file_s
{
	char *name;
	struct stat *statbuf;
} file_t;

/**
 * struct file_s - doubly linked list
 * @File: File struct
 * @next: points to the next node
 * @prev: points to the prev node
 * Description: doubly linked list node structure
 */
typedef struct node_t
{
	file_t *file;
	struct node_t *next;
	struct node_t *prev;
} node_t;

int main(int argc, char **argv);
void listFiles(char* dirname);
int parse_flags(int *flags);

/* error handling error.c*/
/* error.c */
void error_handler(const char *msg);
void print_error_exit(const char *msg);
void error_bad_option(char c);

/* Helper function to print the file information */
/* _strcmp.c */
int _strcmp(char *s1, char *s2);
int _strncpy(char *s1, char *s2, int n);
int _strlen(char *s);

/* print.c */
void printFile(file_t *file);
#endif /*_HLS_H*/
