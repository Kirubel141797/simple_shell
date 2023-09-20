#include "shell.h"

/**
 *exec_fun - A function to be decided a execution based on arguments
 *@_args: An argument
 *@av: arguments to be printed in the name of the shell
 *@env: an eviroment variable
 *@cicles: A number of times the new command is pressed
 *
 *Return: 1 or 0 integer
 */
int exec_fun(int *cicles, char  **_args, char **av, char **env)
{
	int x;
	char *_build_do[] = {"cd", "pwd", "exit", "env"};

	for (x = 0; x < 4; x++)
	{
		if (_strcmp(_args[0], _build_do[l]) == 0)
		{

			return (built_in_handler(_args, env));
		}
	}

	return (exec_handler(cicles, _args, av, env));
}

