#include "hls.h"
/**
 * listFiles - list files in a directory
 * @dirname: directory name
 *
 * Return: void
 */
void listFiles(const char* dirname)
{
	DIR *dir;
	struct dirent *entry;
	struct stat *statbuf;

	if (!(dir = opendir(dirname)))
		print_error_exit("opendir");
	while ((entry = readdir(dir)))
	{
		statbuf = malloc(sizeof(struct stat));
		if (!statbuf)
			print_error_exit("malloc");
		if (lstat(entry->d_name, statbuf) == -1)
			print_error_exit("lstat");
		if (_strcmp(entry->d_name, ".") == 0 ||
			_strcmp(entry->d_name, "..") == 0)
			continue;
		printf("%s ", entry->d_name);
	}
	printf("\n");
	closedir(dir);
	free(statbuf);
}
/**
 * main - main function
 * @argc: Number of arguments
 * @argv: argv Array of arguments
 * @return 0 if success, -1 otherwise
 */
int main(int argc, char **argv)
{
	char *dirname;
	int flags = 0;
	int i = 0;
	int j = 0;

	if (argc > 1)
	{
		for (i = 1; i < argc; i++)
		{
			if (argv[i][0] == '-')
			{
				for (j = 1; argv[i][j] != '\0'; j++)
				{
					if (argv[i][j] == 'a' || argv[i][j] == '1')
						flags |= 1;

				}
			}
			else
			{
				dirname = argv[i];
				listFiles(dirname);
			}
		}
	}
	else
	{
		listFiles(cd);
	}
	return (0);
}
