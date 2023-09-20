#include "shell.h"

/**
  *fun_cd - Changes a directory
  *@_args: An argument with a information of location
  *
  *Return: Always 1
  */
int fun_cd(char **_args)
{
	printf("Entered fun_cd function: %s\n", _args[0]);
	return (1);
}

/**
  *fun_pwd - Prints a current directory
  *@_args:An arguments with a information of location
  *
  *Return: Always 1
  */
int fun_pwd(char **_args)
{
	printf("Entered fun_pwd function: %s\n", _args[0]);
	return (1);
}

/**
  *fun_exit - exit a terminals
  *@_args: An arguments with a information of location
  *
  *Return: Always 0 or 1
  */
int fun_exit(char **_args)
{
	char *ex = "exit";

	if (_strcmp(_args[0], ex) == 0)
	{

		return (0);
	}
	return (1);
}

/**
  *fun_envi - Prints a enviromental variable
  *@env: Anenviromental variable
  *
  *Return: Always 1
  */
int fun_envi(char **env)
{
	int x = 0;

	while (env[x])
	{
		_printf("%s\n", env[x]);
		x++;
	}

	return (1);
}

