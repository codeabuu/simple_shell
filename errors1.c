#include "shell.h"

/**
* _eratoi - converts a string to an integer
* @s: the string to be converted
* Return: 0 if no numbers in string, converted number otherwise
*       -1 on error
*/
int _eratoi(char *s)
{
	int i = 0;
	unsigned long int rslt = 0;

	if (*s == '+')
		s++;

	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
		rslt *= 10;
		rslt += (s[i] - '0');
		if (rslt > INT_MAX)
			return (-1);
		}
		else
			return (-1);
		i++;
	}
	return (rslt);
}

/**
* print_err - prints an error message
* @info: the parameter & return info struct
* @estr: string containing specified error type
* Return: 0 if no numbers in string, converted number otherwise
*        -1 on error
*/
void print_err(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
* print_d - function prints a decimal (integer) number (base 10)
* @input: the input
* @fd: the filedescriptor to write to
*
* Return: number of characters printed
*/
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i = 1000000000, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	
	while (i > 1)
	{
	if (_abs_ / i)
	{
	__putchar('0' + current / i);
	count++;
	}
	current %= i;
	i /= 10;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
* conv_no - converter function, a clone of itoa
* @num: number
* @base: base
* @flags: argument flags
*
* Return: string
*/
char *conv_no(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
* rm_comments - function replaces first instance of '#' with '\0'
* @buf: address of the string to modify
*
* Return: Always 0;
*/
void rm_comments(char *buf)
{
	int i = 0;

	while (buf[i] != '\0')
	{
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
		i++;
	}
}
