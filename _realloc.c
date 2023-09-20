#include "shell.h"

/**
  * _realloc - Functions that are reallocates a memory block
  * @ptr: To block of memory to reallocatre
  * @old_size: A size of a memorry occupied by ptr
  * @new_size: A Size of a new memory to realloc
  *
  * Return: A new reallocated string
  */
void *_realloc(void *ptr, int old_size, int new_size)
{
	char *s;
	int l = 0;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	s = malloc(new_size);
	if (s == NULL)
		return (NULL);
	if (ptr == NULL)
		return (s);
	while (l < new_size && l < old_size)
	{
		s[l] = ((char *) ptr)[l];
		l++;
	}
	free(ptr);
	return (s);
}
