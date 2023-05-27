#include "main.h"
/**
 * free_sep_list - frees a sep_list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_sep_list(sep_list **head)
{
	if (head == NULL || *head == NULL)
		return;

	sep_list *current = *head;
	sep_list *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*head = NULL;
}

/**
 * add_line_node_end - adds a command line at the end
 * of a line_list.
 * @head: head of the linked list.
 * @line: command line.
 * Return: address of the head.
 */
line_list *add_line_node_end(line_list **head, char *line)
{
	line_list *new = malloc(sizeof(line_list));
	if (new == NULL)
		return NULL;

	new->line = line;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		line_list *temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return *head;
}
