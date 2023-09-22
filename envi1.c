#include "main.h"

/**
 * cmp_env_name - compare env variables names
 * with the name passed.
 * @nenv: name of the environment variable
 * @name: name passed
 *
 * Return: 0 if are not equal. Another value if they are.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int x;

	for (x = 0; nenv[x] != '='; x++)
	{
		if (nenv[x] != name[x])
		{
			return (0);
		}
	}

	return (x + 1);
}

/**
 * _getenv - get environment variable
 * @name: name of  environment variable
 * @_environ: environment variable
 *
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int x, move;

	/* Initialize ptr_env value */
	ptr_env = NULL;
	move = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (x = 0; _environ[x]; x++)
	{
		/* If name and env are equal */
		move = cmp_env_name(_environ[x], name);
		if (move)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + move);
}

/**
 * _env - prints the evironment variables
 *
 * @datash: data relevant.
 * Return: 1 on success.
 */
int _env(data_shell *datash)
{
	int x, j;

	for (x = 0; datash->_environ[x]; x++)
	{

		for (j = 0; datash->_environ[x][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environ[x], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
