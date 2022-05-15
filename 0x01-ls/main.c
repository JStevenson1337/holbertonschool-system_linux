#include "hls.h"

#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char * argv[])
{
    DIR *dir;
    struct dirent *ent;
    char *path = ".";


    if (argc > 1)
        path = argv[1];
    
    dir = opendir(path);
    if (dir == NULL)
        return 1;
    
    while ((ent = readdir(dir)) != NULL)
    {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
            continue;
        printf(" %s ", ent->d_name);
    }

    closedir(dir);
    return 0;
}
