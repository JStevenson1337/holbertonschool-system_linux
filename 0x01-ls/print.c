#include "hls.h"

void print_list_1_by_1(const char *dirname)
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
			printf("%s\n", entry->d_name);
		}
	}
	closedir(dir);
}

void print_list_normalized(const char *dirname)
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

void print_list_rev(const char *dirname)
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
			printf("%s\n", entry->d_name);
		}
	}
	closedir(dir);
}

void print_list_time(const char *dirname)
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
			struct stat sb;
			stat(entry->d_name, &sb);
			printf("%s  %s\n", entry->d_name, ctime(&sb.st_mtime));
		}
	}
	closedir(dir);
}

void print_list_size(const char *dirname)
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
			struct stat sb;
			stat(entry->d_name, &sb);
			printf("%s  %lu\n", entry->d_name, sb.st_size);
		}
	}
	closedir(dir);
}
