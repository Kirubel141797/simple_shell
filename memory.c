
#include "shell.h"

/**
 * bfree - free a pointer and NULLs to the address
 * @ptr: address of pointer to the freed
 *
 * Return: 1 if freed otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
