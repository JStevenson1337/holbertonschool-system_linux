#include "hls.h"


/**
 * error_handler - print error message and exit
 * @error: error number
 * @path: path to file
 * @filename: name of file
 * Return: void
 */
void error_handler(int error, const char *path, const char *filename)
{
	if (error == -1)
	{
		if (errno == ENOENT)
		{
			printf("%s: %s: No such file or directory\n", filename, path);
		}
		else if (errno == ENOTDIR)
		{
			printf("%s: %s: Not a directory\n", filename, path);
		}
		else if (errno == EACCES)
		{
			printf("%s: %s: Permission denied\n", filename, path);
		}
		else
		{
			printf("%s: %s: %s\n", filename, path, strerror(errno));
		}
	}
}
