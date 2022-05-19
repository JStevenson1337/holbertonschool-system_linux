#ifndef _HLS_H
#define _HLS_H

#include <dirent.h>
#include <errno.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>




typedef struct error_handler_s
{
	char *directory;
	int error;
} error_handler_t;

typedef struct stat_s
{
	char *name;
	char *permissions;
	char *links;
	char *owner;
	char *group;
	char *size;
	char *date;
	char *time;
	char *type;
} stat_t;



#endif /*_HLS_H*/
