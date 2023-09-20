#include <unistd.h>

/**
* _putchar - To write a character c to stdout
* @c: A character to be  printed
* @p: A pointer to be updated in the length
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c, int *p)
{
	*p += 1;

	return (write(1, &c, 1));
}

