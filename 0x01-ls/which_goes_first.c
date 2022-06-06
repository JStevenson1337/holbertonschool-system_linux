#include "header.h"

/**
 * which_goes_first - returns the string that goes first alphabetically
 * @s1: string1
 * @s2: string2
 * Return: string that goes first alphabetically
 **/
char *which_goes_first(char *s1, char *s2)
{
	char *tmp;

	if (*s1 == '\0')
		return (*s2 ? s1 : NULL);

	if (*s2 == '\0')
		return (s2);

	if (*s1 == '.')
		return (which_goes_first(s2, s1 + 1) == s1 + 1 ? s1 : s2);

	if (*s2 == '.')
		return (which_goes_first(s1, s2 + 1) == s2 + 1 ? s2 : s1);

	if (*s1 + 32 * ISUPPER(*s1) == *s2 + 32 * ISUPPER(*s2))
	{
		tmp = which_goes_first(s1 + 1, s2 + 1);
		if (tmp == s1 + 1)
			return (s1);
		if (tmp == s2 + 1)
			return (s2);
		if (*s1 == *s2)
			return (NULL);
		return (ISLOWER(*s1) ? s1 : s2);
	}

	return ((*s1 + 32 * ISUPPER(*s1)) < (*s2 + 32 * ISUPPER(*s2)) ? s1 : s2);
}
