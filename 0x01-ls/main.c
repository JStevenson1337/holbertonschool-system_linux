#include "hls.h"
#include <stdio.h>
#include <string.h>
#include <dirent.h>


/**
 * @main  Main function
 * @argc Number of functions
 * @argv Array of functions
 */
int main(int argc, char **argv)
{
	// Check if the user has entered a directory
	if (argc < 2)
	{
		printf("Usage: %s <directory>\n", argv[0]);
		return 1;
	}

	// Get the directory
	DIR *dir = opendir(argv[1]);
	if (dir == NULL)
	{
		printf("Error: %s is not a directory\n", argv[1]);
		return 1;
	}

	// Get the directory entries
	struct dirent *entry;
	while ((entry = readdir(dir)) != NULL)
	{
		// Check if the entry is a directory
		if (entry->d_type == DT_DIR)
		{
			// Print the directory name
			printf("%s\n", entry->d_name);
		}
	}

	// Close the directory
	closedir(dir);

	return 0;
}
