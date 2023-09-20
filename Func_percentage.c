#include "shell.h"

/**
  * printChar - It print the single char
  * @p: a pointer to len in _printf;
  * @va: this is the varg argument
  *
  *Return: Void
  */
void printChar(va_list va, int *p)
{
	char c = (char) va_arg(va, int);

	_putchar(c, p);
}

/**
  * printString - a function that print a string
  * @p: a pointer to len in _printf;
  * @va: a varg argument
  *
  *Return: Void
  */
void printString(va_list va, int *p)
{
	char *st = va_arg(va, char*);
	char nu[] = "(null)";
	int l = 0, k = 0;

	if (st == NULL)
	{
		while (nu[k])
		{
			_putchar(nu[k], p);
			k++;
		}
	}
	else
	{
		while (st[l])
		{
			_putchar(st[l], p);
			l++;
		}
	}
}

/**
 * printInt - a function that print an integer
 * @p: a pointer to len in _printf;
 * @va: a varg argument
 *
 *Return: Void
 */
void printInt(va_list va, int *p)
{
	int a;
	int c = va_arg(va, int);

	a = print_Number(c, p);
	p += a;
}

/**
 * printDec - a function that print a decimal number
 * @p: a pointer to len in _printf;
 * @va: an argument
 *
 *Return: Void
 */
void printDec(va_list va, int *p)
{
	int a;
	int c = va_arg(va, int);

	a = print_Number(c, p);
	p += a;
}
