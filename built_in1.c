#include "shell.h"

/**
 * _myhistory - displays history list which is  command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure having potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_i *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - set alias to string
 * @info: parameter struct
 * @str: string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_i *info, char *str)
{
	char *p, t;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	t = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = t;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_i *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_i *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics alias builtin (man alias)
 * @info: Structure having potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_i *info)
{
	int x = 0;
	char *p = NULL;
	list_i *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (x = 1; info->argv[x]; x++)
	{
		p = _strchr(info->argv[x], '=');
		if (p)
			set_alias(info, info->argv[x]);
		else
			print_alias(node_starts_with(info->alias, info->argv[x], '='));
	}

	return (0);
}
