#include "shell.h"

/**
* _eratoi - conva str to an int
* @s: str to be converted
* Return: 0 if no numbers in str, convert number otherwise
*       -1 on error
*/
int _eratoi(char *s)
{
	int i = 0;
	unsigned long int rslt = 0;

	if (*s == '+')
		s++;
	i = 0;
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
* print_err - print an error msg
* @info: parameter & return info structure
* @estr: str containing specified error type
* Return: 0 if no nos in str, conv no otherwise
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
* print_d - function prints a dec (int) no base 10
* @input: the input
* @fd: the fdescriptor to write to
*
* Return: number of chars printed
*/
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
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
	i = 1000000000;
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
* conv_no - conv funct a clone of itoa
* @num: no
* @base: base
* @flags: arg flags
*
* Return: string
*/
char *conv_no(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0, *ptr;
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
* rm_comments - func replace 1st instance of '#' with '\0'
* @buf: add of the str to modify
*
* Return: Always 0;
*/
void rm_comments(char *buf)
{
	int i;

	i = 0;
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
