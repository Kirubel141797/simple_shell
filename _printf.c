#include "shell.h"

/**
  * _printf - To prints chars and a string
  * @format: char with a string formats to be print
  *
  * Return: -1 when an error or the count of chars
  */
int _printf(const char *format, ...)
{
	int l = 0, res = 0, len = 0;
	int *ptr;
	va_list toPrint;

	if (format == NULL)
	{
		return (-1);
	}
	ptr = &len;
	va_start(toPrint, format);

	while (format && format[l])
	{
		if (format[l] == '%')
		{
			res = funper(format, l, toPrint, ptr);
			if (res == -1)
			{
				return (-1);
			}
			if (!res)
			{
				va_end(toPrint);
				return (len);
			}
			l += res;
			continue;

		}
		else
		{
			 _putchar(format[l], ptr);
		}
		l++;
	}
	va_end(toPrint);
	return (len);
}
