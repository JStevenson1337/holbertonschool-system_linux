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
#include <string.h>

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

#define FLAG_1 0001
#define FLAG_a 0010
#define FLAG_A 0100
#define FLAG_l 1000
#define FLAG_R 1100
#define FLAG_r 0101
#define FLAG_S 0111
#define FLAG_t 1111


/**
 * struct file_s - doubly linked list
 * @File: File struct
 * @next: points to the next node
 * @prev: points to the prev node
 * Description: doubly linked list node structure
 */
typedef struct node_s
{
	char *dirname;
	char *fullpath;
	struct stat *statbuf;
	node_t *next;++
} node_t;


int main(int argc, char **argv);
void listFiles(char* dirname);
void parse_flags(int *flags, int *i);
char *base_name(char *fullpath);

/* error handling error.c*/
/* error.c */
void error_handler(const char *msg);
void print_error_exit(const char *msg);


/* Helper function to print the file information */
/* _strcmp.c */
int _strcmp(char *s1, char *s2);
int _strncpy(char *s1, char *s2, int n);
int _strlen(char *s);

/* print.c */

/* nodebuilder.c */
node_t *create_node(char *dirname, char *fullpath, struct stat *statbuf);
#endif /*_HLS_H*/
