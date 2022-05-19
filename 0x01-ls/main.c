#include "hls.h"


/**
 * hls - Converts a directory to a list of files
 * @dir: The directory to convert
 * @op_a: option a
 * @op_1: option 1
*/
void hls(const char *dir, int op_a, int op_1)
{
	struct dirent *d;
	DIR *dh = opendir(dir);

	if (!dh)
	{
		if (errno == ENOENT)
		{
			perror("Directory doesn't exist");
		}
		else
		{
			perror("Unable to read directory");
		}
		exit(EXIT_FAILURE);
	}
	while ((d = readdir(dh)) != NULL)
	{
		if (!op_a && d->d_name[0] == '.')
			continue;
		printf("%s  ", d->d_name);
		if (op_1)
		{
			printf("\n");
		}
	}
	if (!op_1)
	printf("\n");
}

/**
 * main - main program
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: List of nodes
*/
int main(int argc, const char *argv[])
{

	if (argc == 1)
	{
		hls(".", 0, 0);
	}
	else if (argc == 2)
	{
		if (argv[1][0] == '-')
		{
			int op_a = 0, op_1 = 0;
			char *p = (char *)(argv[1] + 1);

			while (*p)
			{
				if (*p == 'a')
				{
					op_a = 1;
				}
				else if (*p == '1')
				{
					op_1 = 1;
				}
				else
				{
					perror("Option not available");
					exit(EXIT_FAILURE);
				}
				p++;
			}
			hls(".", op_a, op_1);
		}
	}
	return (0);
}
