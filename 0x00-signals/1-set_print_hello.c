
#include "signals.h"
/**
 * print_hello - prints hello
 * @num: the signal number
 *
 * Return: void
 */
void print_hello(int num)
{
	(void) num;
	puts("Hello :)");
	fflush(stdout);
}
/**
 * set_print_hello - set the handler for SIGINT to print_hello
 * Return: void
 */
void set_print_hello(void)
{
	signal(SIGINT, print_hello);
}
