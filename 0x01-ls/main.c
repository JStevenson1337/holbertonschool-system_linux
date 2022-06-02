#include "hls.h"
/**
 * listFiles - list files in a directory
 * @dirname: directory name
 *
 * Return: void
 */
void listFiles(const char* dirname)
{
	DIR* dir = opendir(dirname);
	struct dirent* entry;

	if (!dir)
	{
		error_handler(errno, dirname, "hls");
		return;
	}

	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] != '.')
		{
			printf("%s  ", entry->d_name);
		}
	}
	printf("\n");
	closedir(dir);
}
/**
 * main - main function
 * @argc: Number of arguments
 * @argv: argv Array of arguments
 * @return 0 if success, -1 otherwise
 */
int main(int argc, char **argv)
{
	if (!argc || argv == NULL)
	{
		return (-1);
	}
	if (argc == 1)
	{
		listFiles(".");
	}
	else
	{
		listFiles(argv[1]);
	}
	return (0);
}
