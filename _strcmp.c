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
	int l, j, a, b;

	l = 0;

	while (s1[l] == s2[l] && s1[l] != '\0' && s2[l] != '\0')
	{
		/*printf("got into the _strcmp cycle");*/
		l++;
	}
	a = (s1[l] - '0');
	b = (s2[l] - '0');
	j = a - b;

	return (j);
}

