#include "shell.h"

/**
 * bfree - will free a pointer & NULLs the address
 * @pointer: address of pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **pointer)
{
	if (pointer && *pointer)
	{
		free(*pointer);
		*pointer = NULL;
		return (1);
	}
	return (0);
}
