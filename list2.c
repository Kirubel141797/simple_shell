
#include "main.h"

/**
 * add_rvar_node - add a variable at the end
 * of a r_var list.
 * @head: head of linked list.
 * @lvar: length of variable.
 * @val: value of variable.
 * @lval: length of value.
 * Return: address of the head.
 */
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
	r_var *new, *tem;

	new = malloc(sizeof(r_var));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

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
		temp->next = new;
	}

	return (*head);
}

/**
 * free_rvar_list - frees a r_var list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_rvar_list(r_var **head)
{
	r_var *tem;
	r_var *curr;

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
