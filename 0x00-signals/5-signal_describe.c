#include "signals.h"

#define USAGE "Usage: %s <signum>\n"

/**
 * _atoi - convert a string to an integer
 * @s: string to convert
 * Return: integer
 */
int _atoi(char *s)
{
	int i, sign, num;

	i = 0;
	sign = 1;
	num = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
			num = num * 10 + (s[i] - '0');
		else if (num > 0)
			break;
		i++;
	}
	return (num * sign);
}

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
	if (strsignal(_atoi(argv[1])))
		printf("%d: %s\n", _atoi(argv[1]), strsignal(_atoi(argv[1])));
	else
		printf("%d Unknown signal %d\n", _atoi(argv[1]), _atoi(argv[1]));
	return (EXIT_SUCCESS);
}
