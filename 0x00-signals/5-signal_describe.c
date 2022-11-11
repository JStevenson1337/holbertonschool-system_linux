#include "signals.h"

#define USAGE "Usage: %s <signum>\n"
/**
 * main - entry point
 * @argc: Count of arguments
 * @argv: Vector of arguments
 * Return: Success or Failure
 */
int main(int argc, char **argv)
{
	if (argc != 2)
		return (printf(USAGE, argv[0]), EXIT_FAILURE);
	if (strsignal(atoi(argv[1])))
		printf("%d: %s\n", atoi(argv[1]), strsignal(atoi(argv[1])));
	else
		printf("%d Unknown signal %d\n", atoi(argv[1]), atoi(argv[1]));
	return (EXIT_SUCCESS);
}
