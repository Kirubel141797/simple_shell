#include "shell.h"

/**
 * _myenv - prints current environment
 * @info: Structure having potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenv(info_i *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets value of an environ variable
 * @info: Structure having potential arguments used  to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_i *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize new environment variable,
 *             or modify an existing one
 * @info: Structure having potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(info_i *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure having potential arguments used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myunsetenv(info_i *info)
{
	int x;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (x = 1; x <= info->argc; x++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - populate env linked list
 * @info: Structure having potential arguments used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_i *info)
{
	list_i *node = NULL;
	size_t x;

	for (x = 0; environ[x]; x++)
		add_node_end(&node, environ[x], 0);
	info->env = node;
	return (0);
}
