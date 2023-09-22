#include "main.h"

/**
 * add_sep_node_end - add a separator found at the end
 * of a sep_list.
 * @head: head of linked list.
 * @sep: separator found (; | &).
 * Return: address of the head.
 */
sep_list *add_sep_node_end(sep_list **head, char sep)
{
	sep_list *new, *tem;

	new = malloc(sizeof(sep_list));
	if (new == NULL)
		return (NULL);

	new->separator = sep;
	new->next = NULL;
	tem = *head;

	if (tem == NULL)
	{
		*head = new;
	}
	else
	{
		while (tem->next != NULL)
			tem = tem->next;
		tem->next = new;
	}

	return (*head);
}

/**
 * free_sep_list - free a sep_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_sep_list(sep_list **head)
{
	sep_list *tem;
	sep_list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((tem = curr) != NULL)
		{
			curr = curr->next;
			free(tem);
		}
		*head = NULL;
	}
}

/**
 * add_line_node_end - add command line at the end
 * of a line_list.
 * @head: head of the linked list.
 * @line: command line.
 * Return: address of the head.
 */
line_list *add_line_node_end(line_list **head, char *line)
{
	line_list *new, *tem;

	new = malloc(sizeof(line_list));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	tem = *head;

	if (tem == NULL)
	{
		*head = new;
	}
	else
	{
		while (tem->next != NULL)
			tem = tem->next;
		tem->next = new;
	}

	return (*head);
}

/**
 * free_line_list - free a line_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_line_list(line_list **head)
{
	line_list *tem;
	line_list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((tem = curr) != NULL)
		{
			curr = curr->next;
			free(tem);
		}
		*head = NULL;
	}
}
