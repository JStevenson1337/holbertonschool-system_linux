#include "multithreading.h"
#include <stdlib.h>

/**
 * prime_factors - factors a number into a list of prime factors
 * @s: string representationum of the number to factor
 * Return: list_t of prime factors
 **/
list_t *prime_factors(char const *s)
{
	unsigned long num = strtoul(s, NULL, 10);
	unsigned long *temp, point = 2;
	list_t *list = malloc(sizeof(list_t));

	list_init(list);
	while (point * point <= num)
	{
		while (num % point == 0)
		{
			temp = malloc(sizeof(unsigned long));
			*temp = point;
			list_add(list, (void *)temp);
			num /= point;
		}

		point += 1 + (point != 2);
	}

	if (num >= 2)
	{
		temp = malloc(sizeof(unsigned long));
		*temp = num;
		list_add(list, (void *)temp);
	}
	return (list);
}
