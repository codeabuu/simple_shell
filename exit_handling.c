#include "shell.h"

/**
**_strncpy - copies a string
*@dest: the destination string to be copied to
*@source: the source string
*@n: the amount of characters to be copied
*Return: the concatenated string
*/
char *_strncpy(char *dest, char *source, int n)
{
	int i, j;
	char *s = dest;

	for (i = 0; source[i] != '\0' && i < n - 1; i++)
	{
		dest[i] = source[i];
	}
	if (i < n)
	{
		for (j = i; j < n; j++)
		{
			dest[j] = '\0';
		}
	}
	return (s);
}

/**
**_strncat - concatenates two strings
*@dest: the first string
*@source: the second string
*@n: the amount of bytes to be maximally used
*Return: the concatenated string
*/
char *_strncat(char *dest, char *source, int n)
{
	int i, j;
	char *s = dest;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; source[j] != '\0' && j < n; j++)
	{
		dest[i] = source[j];
		i++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
**_strchr - will locate a character in a string
*@s: string to be parsed
*@c: character to look for
*Return: (s) a pointer to the memory area s
*/
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
