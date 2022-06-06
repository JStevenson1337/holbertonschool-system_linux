#include "hls.h"
/**
 * listFiles - list files in a directory
 * @dirname: directory name
 *
 * Return: void
 */
void listFiles(char* dirname)
{
	DIR *dir;
	struct dirent *entry;
	struct stat statbuf;

	if ((dir = opendir(dirname)) == NULL)
	{
		print_error_exit("hls: opendir error: ");
	}
	while ((entry = readdir(dir)) != NULL)
	{
		if (stat(entry->d_name, &statbuf) == -1)
		{
			print_error_exit("hls: stat error: ");
		}
		if (S_ISDIR(statbuf.st_mode))
		{
			if (_strcmp(".", entry->d_name) == 0 ||
				_strcmp("..", entry->d_name) == 0)
				continue;
			printf("%s ", entry->d_name);
			listFiles(entry->d_name);
		}
		else
		{
			printf("%s ", entry->d_name);
		}
	}
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
	int i, flags[3];
	char *dirname;

	if (argc < 2)
	{
		listFiles(".");
		return (0);
	}
	for (i = 1; i < argc; i++)
	{
		if (argv[i][0] == '-')
		{
			parse_flags(flags, &i);
		}
		else
		{
			dirname = argv[i];
			listFiles(dirname);
		}
	}
	return (0);
}

/**
 * base_name - returns pointer to base name of file
 * @fullpath: the full path file name
 * Return: pointer to base name of string
 */
char *base_name(char *fullpath)
{
	char *ptr;

	ptr = strrchr(fullpath, '/');
	if (ptr == NULL)
		return (fullpath);
	return (ptr + 1);
}

void parse_flag(char *flag, int *flags)
{
	int i;

	for (i = 1; flag[i] != '\0'; i++)
	{
		switch (flag[i])
		{
		case '1':
			flags[0] |= 0001;
			break;
		case 'a':
			flags[0] |= 0010;
			break;
		}
	}
}
