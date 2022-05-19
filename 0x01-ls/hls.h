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

unsigned int error_handler(char *dir);
unsigned int hls(int argc, char *argv[]);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


#endif /*_HLS_H*/
