#include "shell.h"

/**
* _strlen - returns length of a str
* @s: the string whose length to check
*
* Return: int leng of str
*/
int _strlen(char *s)
{
	int i;

	if (!s)
		return (0);

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}

/**
* _strcmp - performs lexical comparison of two strings.
* @s1: the first string
* @s2: the second string
*
* Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
*/
int _strcmp(char *s1, char *s2)
{
	for (; *s1 && *s2 && (*s1 == *s2); s1++, s2++)
		;
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
* starts_with - checks if needle starts with haystack
* @haystack: string to search
* @needle: the substring to find
*
* Return: address of next character of haystack or NULL
*/
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
* _strcat - concatenates two strings
* @dest: the destination buffer
* @source: the source buffer
*
* Return: pointer to destination buffer
*/
char *_strcat(char *dest, char *source)
{
	char *ret = dest;

	for (; *dest; ++dest)
	{
	}
	for (; *source; ++source, ++dest)
	{
		*dest = *source;
	}
	*dest = '\0';

	return (ret);
}
