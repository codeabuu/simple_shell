#include "shell.h"

/**
 * _setmem - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */
char *_setmem(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
	s[i] = b;
	i++;
	}
	return (s);
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	for (; *pp; pp++)
	{
		free(*pp);
	}
	free(a);
}

/**
 * _realloc - reallocates a block of memory
 * @pointer: pointer to previous memory allocated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to the block names.
 */
void *_realloc(void *pointer, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!pointer)
		return (malloc(new_size));
	if (!new_size)
		return (free(pointer), NULL);
	if (new_size == old_size)
		return (pointer);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)pointer)[old_size];
	free(pointer);
	return (p);
}
