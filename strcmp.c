#include "shell.h"

/**
 *_strcmp - evaluate is a char is less , equal or higher than other strings
 *@s1: A destination of  string
 *@s2: An origin of string
 *
 *Return: Char string
 */
int _strcmp(char *s1, char *s2)
{
	int x, j, a, b;

	x = 0;

	while (s1[x] == s2[x] && s1[x] != '\0' && s2[x] != '\0')
	{
		/*printf("got into the _strcmp cycle");*/
		x++;
	}
	a = (s1[x] - '0');
	b = (s2[x] - '0');
	j = a - b;

	return (j);
}

