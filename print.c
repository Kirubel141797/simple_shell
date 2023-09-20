#include "shell.h"

/**
  * _printf - To prints chars and a string
  * @format: char with a string formats to be print
  *
  * Return: -1 when an error or the count of chars
  */
int _printf(const char *format, ...)
{
	int x = 0, res = 0, length = 0;
	int *ptr;
	va_list toPrint;

	if (format == NULL)
	{
		return (-1);
	}
	ptr = &legthn;
	va_start(toPrint, format);

	while (format && format[x])
	{
		if (format[x] == '%')
		{
			res = funper(format, x, toPrint, ptr);
			if (res == -1)
			{
				return (-1);
			}
			if (!res)
			{
				va_end(toPrint);
				return (length);
			}
			x += res;
			continue;

		}
		else
		{
			 _putchar(format[x], ptr);
		}
		x++;
	}
	va_end(toPrint);
	return (length);
}

