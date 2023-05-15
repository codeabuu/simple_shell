#include "shell.h"

/**
* _eputs - print an input string stderr
* @str: string to be printed
*
* Return: Nothing
*/
void _eputs(char *str)
{
	int i;

	if (!str)
		return;

	for (i = 0; str[i] != '\0'; i++)
	{
	_eputchar(str[i]);
	}
}
/**
* _eputchar - writes character c to stderr
* @c: The character to print
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
* _putfd - writes character c to given file descriptor
* @c: The character to print
* @fd: The file descriptor to write to
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
* _putsfd - prints an input string to the given file descriptor
* @str: string to be printed
* @fd: file descriptor to write to
*
* Return: the number of chars put
*/
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
	return (0);

	for (i = 0; str[i] != '\0'; i++)
	{
	i += _putfd(str[i], fd);
	}

	return (i);
}
