#include "multithreading.h"
#include <pthread.h>
/**
 * tprintf - Format print a thread
 *
 * @format: Pointer to string
 * Return: 0 on success NULL on fail
 */
int tprintf(char const *format, ...)
{

	if (format != NULL)
	{
		printf("[%lu] %s", pthread_self(), format);
		return (0);
	}
	pthread_exit(&format);
}
