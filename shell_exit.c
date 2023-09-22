#include "main.h"

/**
 * exit_shell - exit the shell
 *
 * @datash: data relevant
 * Return: 0 on success.
 */
int exit_shell(data_shell *datash)
{
	unsigned int ustatus;
	int is_dig;
	int str_len;
	int big_numb;

	if (datash->args[1] != NULL)
	{
		ustatus = _atoi(datash->args[1]);
		is_dig = _isdigit(datash->args[1]);
		str_len = _strlen(datash->args[1]);
		big_numb = ustatus > (unsigned int)INT_MAX;
		if (!is_dig || str_len > 10 || big_numb)
		{
			get_error(datash, 2);
			datash->status = 2;
			return (1);
		}
		datash->status = (ustatus % 256);
	}
	return (0);
}
