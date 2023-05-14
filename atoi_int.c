#include "shell.h"

/**
* interact - will return true if shell is interactive mode
* @info: struct addr
*
* Return: 1 if interact mode, else 0
*/
int interact(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
* is_delimeter - check if char is delimeter
* @c: char to check
* @delim: delimeter str
* Return: 1 if true, 0 is false
*/
int is_delimeter(char c, char *delim)
{
while (*delim != '\0')
{
if (*delim == c)
{
return (1);
}
delim++;
}
return (0);
}
/**
* _isalpha - check for alpha chars
* @c: The character to input
* Return: 1 if c is alphabetic, 0 otherwise
*/

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
* _atoi - converts a string to an integer
* @s: the string to be converted
* Return: 0 if no numbers in string, converted number otherwise
*/

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int rslt = 0;
i = 0;
while (s[i] != '\0' && flag != 2)
{
if (s[i] == '-')
	{
sign *= -1;
}
if (s[i] >= '0' && s[i] <= '9')
	{
flag = 1;
rslt *= 10;
rslt += (s[i] - '0');
}

else if (flag == 1)
	{
flag = 2;
}
i++;
}

if (sign == -1)
{
output = -rslt;
}
else
{
output = rslt;
}

return (output);
}
