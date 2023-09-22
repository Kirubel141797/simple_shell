#include "main.h"

/**
 * _memcpy - copy information between void pointers.
 * @newptr: destination pointer.
 * @ptr: source pointer.
 * @size: size of new pointer.
 *
 * Return: no return.
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int x;

	for (x = 0; x < size; x++)
		char_newptr[x] = char_ptr[x];
}

/**
 * _realloc - reallocate a memory block.
 * @ptr: pointer to  memory previously allocated.
 * @old_size: size, in bytes, of the allocated space of ptr.
 * @new_size: new size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * if new_size == old_size, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newpt;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newpt = malloc(new_size);
	if (newpt == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newpt, ptr, new_size);
	else
		_memcpy(newpt, ptr, old_size);

	free(ptr);
	return (newpt);
}

/**
 * _reallocdp - reallocate a memory block of a double pointer.
 * @ptr: double pointer to memory previously allocated.
 * @old_size: size, in bytes, of the allocated space of ptr.
 * @new_size: new size, in bytes, of the new memory block.
 *
 * Return: ptr.
 * if new_size == old_size, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newpt;
	unsigned int x;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newpt = malloc(sizeof(char *) * new_size);
	if (newpt == NULL)
		return (NULL);

	for (x = 0; x < old_size; x++)
		newpt[x] = ptr[x];

	free(ptr);

	return (newpt);
}
