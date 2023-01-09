#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
extern **environ;
/**
 * main - Entry Point
 * argc: argument count
 * argv: argument vector
 *
 * ONLY parameter to be passed in 
 * fully qualified path of binary file
 *      ie "./ex0 /usr/bin/ls"
*/
int main(int argc, char *argv[])
{
    int i = 0;

    for (i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }

    while (environ[i] != NULL)
    {
        printf("%i\n", environ[i]);
        i++;
    }
    

	return 0;
}
