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
			print_list_normalized(entry->d_name);
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
int main(int argc, char *argv[])
{
	int i;
	int **flag = 0;

	if (argc < 2)
	{
		listFiles(current_directory);
		return (0);
	}

	flag = malloc(sizeof(int *) * argc);
	if (!flag)
	{
		error_handler(-1, "", "hls");
		return (-1);
	}

	for (i = 0; i < argc; i++)
	{
		flag[i] = malloc(sizeof(int) * 2);
		if (!flag[i])
		{
			error_handler(-1, "", "hls");
			return (-1);
		}
		flag[i][0] = 0;
		flag[i][1] = 0;
	}

	for (i = 1; i < argc; i++)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == 'R')
			{
				flag[i][0] = 1;
				flag[i][1] = 1;
			}
			else if (argv[i][1] == 'a')
			{
				flag[i][0] = 1;
				flag[i][1] = 2;
			}
			else if (argv[i][1] == 't')
			{
				flag[i][0] = 1;
				flag[i][1] = 3;
			}
			else if (argv[i][1] == 'S')
			{
				flag[i][0] = 1;
				flag[i][1] = 4;
			}
			else if (argv[i][1] == '1')
			{
				flag[i][0] = 1;
				flag[i][1] = 5;
			}
			else
			{
				error_handler(-1, "", "hls");
				return (-1);
			}
		}
		else
		{
			listFiles(argv[i]);
		}
	}

	for (i = 1; i < argc; i++)
	{
		if (flag[i][0] == 1)
		{
			switch (flag[i][1])
			{
			case 1:
				print_list_1_by_1(argv[i]);
				break;
			case 2:
				print_list_normalized(argv[i]);
				break;
			case 3:
				print_list_time(argv[i]);
				break;
			case 4:
				print_list_size(argv[i]);
				break;
			case 5:
				print_list_1_by_1(argv[i]);
				break;
			default:
				error_handler(-1, "", "hls");
				return (-1);
			}
		}
	}

	return (0);
}

