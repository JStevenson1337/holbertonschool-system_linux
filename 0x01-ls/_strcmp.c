#include "hls.h"

/**
 * mystrcmp - compares two strings together
 * @s1: the destination string
 * @s2: the string part we are adding to dest
 * Return: integer positive if s1 is sooner alphabetically, negative if later
 */
int _strcmp(char *s1, char *s2)
{

	/* keep going through the letters while they are the same */
	while (*s1 != '\0' && *s2 != '\0' && *s1 - *s2 == 0)
	{
		s1++;
		s2++;
	}
	/* now return the difference */
	return (int) (*s1 - *s2);
}

int _strncpy(char *s1, char *s2, int n)
{
	int i = 0;

	while (i < n && s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	while (i < n)
	{
		s1[i] = '\0';
		i++;
	}
	return (0);
}


int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
