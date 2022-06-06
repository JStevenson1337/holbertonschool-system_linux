#include "header.h"

/**
* duplicate_string - returns a pointer to duplicate of str
* @str: string to be copied to newly allocated memory space
* Return: char pointer to string, or NULL if memory allocation fails
*/
char *duplicate_string(char *str)
{
	int i, len;
	char *ptr;

	if (str == NULL)
		return (NULL);
	for (len = 0; str[len]; len++) /* get string length */
		;
	len++;
	ptr = (char *)malloc(len); /* allocate memory */
	if (ptr == NULL)		   /* check for NULL */
		return (NULL);
	for (i = 0; i < len; i++) /* copy string */
		ptr[i] = str[i];
	return (ptr); /* return pointer */
}

/**
 * find_char - returns a pointer to the first instance of a char 'c' in str
 * @str: string
 * @c: char to find in string
 * Return: pointer to first instance of 'c' . If c not in str, NULL is returned
 **/
char *find_char(char *str, char c)
{
	if (!str)
		return (NULL);

	while (*str)
		if (*str != c)
			str++;
		else
			return (str);

	return (NULL);
}

/**
 * copy_string - custom strcpy
 * @dest: destination buffer
 * @src: source string
 * Return: pointer to dest
 **/
char *copy_string(char *dest, char *src)
{
	int i;

	if (!dest || !src)
		return (NULL);

	for (i = 0; src[i]; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
* len - returns the length of a string
* @s: string to be evaluated
* Return: integer representing length of string
**/
int len(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}
