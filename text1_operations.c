#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	(c == BUF_FLUSH || i >= WRITE_BUF_SIZE) ? (write(1, buf, i), i = 0) : 0;
	(c != BUF_FLUSH) ? (buf[i++] = c) : 0;
	return (1);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	length++;
	while (length--)
	{
		ret[length] = *--str;
	}
	return (ret);
}

/**
 * _puts - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	for (; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}
/**
 * _strcpy - copies a string
 * @dest: the destination
 * @source: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *source)
{
	int i;

	if (dest == source || source == 0)
		return (dest);
	for (i = 0; source[i]; i++)
	{
		dest[i] = source[i];
	}
	dest[i] = 0;
	return (dest);
}
