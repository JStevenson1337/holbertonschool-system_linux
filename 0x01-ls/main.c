/**
 *
 *
 *
 *
 *
 */
#include "header.h"

int hls(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *ptr;
    char base[1000];

    if ((dir=opendir(argv[1])) == NULL)
    {
        perror("Open dir error...");
        exit(1);
    }

    while ((ptr=readdir(dir)) != NULL)
    {
        if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)    ///current dir OR parrent dir
            continue;
        else if(ptr->d_type == 8)    ///file
            printf("d_name:%s/%s d_type:file d_ino:%d d_reclen:%d d_off:%d  d_reclen:%d d_off:%d  d_reclen:%d d_off:%d  d_reclen:%d d_off:%d");

        else if(ptr->d_type == 10)    ///link file
            printf("d_name:%s/%s d_type:link file d_ino:%d d_reclen:%d d_off:%d  d_reclen:%d d_off:%d  d_reclen:%d d_off:%d  d_reclen:%d d_off:%d");

        else if(ptr->d_type == 4)    ///dir
            printf("d_name:%s/%s d_type:dir d_ino:%d d_reclen:%d d_off:%d  d_reclen:%d d_off:%d  d_reclen:%d d_off:%d  d_reclen:%d d_off:%d");
    }
    closedir(dir);
    return 0;
}

int main(int argc, const char *argv[])
{
    hls(argc, argv);
    return 0;
}

