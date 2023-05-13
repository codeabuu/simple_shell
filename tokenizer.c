#include "shell.h"

/**
* **strtow - splits a string into words. Repeat delimiters are ignored
* @str: the input string
* @d: the delimeter string
* Return: a pointer to an array of strings, or NULL on failure
*/

char **strtow(char *str, char *d)
{
	int i, j, k, m, no_words = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delimeter(str[i], d) && (is_delimeter(str[i + 1], d) || !str[i + 1]))
			no_words++;
	if (no_words == 0)
		return (NULL);
	s = malloc((1 + no_words) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < no_words; j++)
	{
		for (; is_delimeter(str[i], d); i++)
			;
		for (k = 0; !is_delimeter(str[i + k], d) && str[i + k]; k++)
			;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			k = 0;
			while (k < j)
			{
				free(s[k]);
				k++;
			}
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
* **strtow2 - splits a string into words
* @str: the input string
* @d: the delimeter
* Return: a pointer to an array of strings, or NULL on failure
*/
char **strtow2(char *str, char d)
{
	int i, j, k, m, no_words = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
				    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			no_words++;
	if (no_words == 0)
		return (NULL);
	s = malloc((1 + no_words) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < no_words; j++)
	{
		for (i = 0; str[i] == d && str[i] != d; i++)
			;
		for (k = 0; str[i + k] != d && str[i + k] && str[i + k] != d; k++)
			;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		m = 0;
		while (m < k)
		{
			s[j][m] = str[i++];
			m++;
		}
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
