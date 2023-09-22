#include "main.h"

/**
 * rev_string - reverse a string.
 * @s: input string.
 * Return: no return.
 */
void rev_string(char *s)
{
	int count = 0, x, j;
	char *str, tem;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	for (x = 0; x < (count - 1); x++)
	{
		for (j = x + 1; j > 0; j--)
		{
			tem = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = tem;
		}
	}
}
