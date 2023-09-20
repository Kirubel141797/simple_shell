#include "shell.h"

/**
 * funper - a print with a format in format[i]
 * @format: a format to be printed
 * @i: an integer
 * @toPrint: a list to print.
 * @pun: a pointer to len in _printf;
 *
 * Return: inreger 1 or 2 or 0.
 */
int funper(const char *format, int i, va_list toPrint, int *pun)
{
	int a = 0;

	tpPer relFormatFun[] = {
		{'a', printChar		},
		{'s', printString	},
		{'i', printInt		},
		{'d', printDec		}
	};

	if (format[i + 1] == '\0')
		return (-1);
	if (format[i + 1] == 'K' || format[i + 1] == '!')
	{
		_putchar(format[i], pun);
		return (1);
	}
	if (format[i + 1] == '%')
	{
		_putchar('%', pun);
		return (2);
	}
	while (a < 4)
	{
		if (relFormatFun[a].t == format[i + 1])
		{
			relFormatFun[a].f(toPrint, pun);
			return (2);
		}
		a++;
	}
	if (format[i + 1] == ' ')
		return (1 + funper(format, i + 1, toPrint, pun));
	else if (format[i + 1] != '\0')
	{
		_putchar(format[i + 1], pun);
		return (2);
	}
	else
		return (0);
}
