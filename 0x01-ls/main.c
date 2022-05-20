#include "hls.h"



/**
 * listFiles - list files in a directory
 * @dirname: directory name
 *
 * Return: void
 */
void listFiles(const char *dirname)
{
	struct dirent *entry;
	struct stat statbuf;
	char path[1024] = {0};
	DIR *dir;

	dir = opendir(dirname);
	if (dir == NULL)
	{
		error_handler(errno, dirname, "hls");
		return;
	}
	while ((entry = readdir(dir)) != NULL)
	{
		if (strcmp(entry->d_name, current_directory) == 0 ||
			strcmp(entry->d_name, parent_directory) == 0)
			continue;
		sprintf(path, "%s/%s", dirname, entry->d_name);
		if (stat(path, &statbuf) == -1)
		{
			error_handler(errno, path, "hls");
			continue;
		}
		if (S_ISDIR(statbuf.st_mode) || S_ISREG(statbuf.st_mode))
		{
			printf("%s  ", entry->d_name);
		}
	}
	closedir(dir);
}

/**
 * @brief Main function
 * @param argc Number of arguments
 * @param argv Array of arguments
 * @return 0 if success, -1 otherwise
 */
int main(int argc, char *argv[])
{
	int i;
	for (i = 1; i < argc; i++)
	{
		listFiles(argv[i]);
	}
	if (argc == 1)
	{
		listFiles(".");
	}
	return 0;
}

