#include "main.h"

/**
 * without_comment - delete comment from the input
 *
 * @in: input string
 * Return: input without comment
 */
char *without_comment(char *in)
{
	int x, up_to;

	up_to = 0;
	for (x = 0; in[x]; x++)
	{
		if (in[x] == '#')
		{
			if (x == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[x - 1] == ' ' || in[x - 1] == '\t' || in[x - 1] == ';')
				up_to = x;
		}
	}

	if (up_to != 0)
	{
		in = _realloc(in, x, up_to + 1);
		in[up_to] = '\0';
	}

	return (in);
}

/**
 * shell_loop - Loop of shell
 * @datash: data relevant
 *
 * Return: no return.
 */
void shell_loop(data_shell *datash)
{
	int loope, i_eof;
	char *input;

	loope = 1;
	while (loope == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		input = read_line(&i_eof);
		if (i_eof != -1)
		{
			input = without_comment(input);
			if (input == NULL)
				continue;

			if (check_syntax_error(datash, input) == 1)
			{
				datash->status = 2;
				free(input);
				continue;
			}
			input = rep_var(input, datash);
			loope = split_commands(datash, input);
			datash->counter += 1;
			free(input);
		}
		else
		{
			loope = 0;
			free(input);
		}
	}
}
