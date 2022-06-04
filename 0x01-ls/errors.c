#include "hls.h"

void error_handler(const char *msg)
{
	fprintf(stderr, "%s", msg);
	exit(1);
}

void print_error_exit(const char *msg)
{
	error_handler(msg);
	exit(1);
}
