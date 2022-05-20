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


#endif /*_HLS_H*/
