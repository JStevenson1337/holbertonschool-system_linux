#include "include/main.h"
/**
 * main - entry point
 * @ac: argument count
 * @argv: argument vector
 * Return: 0 on success or 1+ on error
 */
int main(int argc, char **argv)
{
	int ret = EXIT_SUCCESS;
	char **_argv = argv;

	if (argc < 2)
		return (fprintf(stderr, DEFAULT_STRING), EXIT_FAILURE);
	if (argc == 2)
		return (read_in_file(argv[1], 0, argv));
	while (*++_argv)
		ret += read_in_file(*_argv, 1, argv);
	return (ret);
}

int read_in_file(char *file_name, int multiple, char **argv)
{

}
