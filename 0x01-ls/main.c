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
	file_t *file;

	if (!(dir = opendir(dirname)))
		print_error_exit("hls: cannot open directory: ");
	while ((entry = readdir(dir)))
	{
		if (entry->d_name[0] != '.')
		{
			file = malloc(sizeof(BUF_SIZE));
			if (!file)
				print_error_exit("hls: malloc error: ");
			file->name = entry->d_name;
			file->statbuf = malloc(sizeof(struct stat));
			if (!file->statbuf)
				print_error_exit("hls: malloc error: ");
			if (stat(entry->d_name, file->statbuf) == -1)
				print_error_exit("hls: cannot access: ");
			if (S_ISDIR(file->statbuf->st_mode))
				listFiles(entry->d_name);
			else
				printFile(file);
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
	int flags = 0;
	int i = 1;
	char *dirname = cd;
	node_t *head = NULL;
	node_t *tmp = NULL;

	if (argc == 1)
	{
		listFiles(dirname);
		return (0);
	}
	else if (argc == 2)
	{
		if (argv[1][0] == '-')
		{
			parse_flags(&flags, &i);
			listFiles(dirname);
			return (0);
		}
		else
		{
			dirname = argv[1];
			listFiles(dirname);
			return (0);
		}

	}
	else if (argc > 2)
	{
		parse_flags(&flags, &i);
		while (i < argc)
		{
			if (argv[i][0] == '-')
			{
				error_bad_FLAG(&argv[i][0]);
			}
			else
			{
				dirname = argv[i];
				listFiles(dirname);
			}
			i++;
		}
	}
	return (0);
}

void parse_flags(int *flags, int *argv)
{
	while (*++argv)
	switch (*argv)
	{
	case '1':
		*flags |= FLAG_1;
		break;
	default:
		error_bad_FLAG(argv);
		free(flags);
		break;
	}
}

/**
 * base_name - returns pointer to base name of file
 * @fullpath: the full path file name
 * Return: pointer to base name of string
 */
char *base_name(char *fullpath)
{
	char *p;

	if (!fullpath)
		return (NULL);
	if (!*fullpath)
		return (fullpath);
	p = fullpath + _strlen(fullpath) - 1;
	for (; p >= fullpath; p--)
	{
		if (*p == '/')
		{
			if (*(p + 1))
				return (p + 1);
			return (p);
		}
	}
	return (fullpath);
}
