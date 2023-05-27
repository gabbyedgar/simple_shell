#include "main.h"
/**
 * free_rvar_list - frees a r_var list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_rvar_list(r_var **head)
{
	r_var *temp;
	r_var *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
			char *dir = datash->args[1];

	if (is_directory_change(dir))
		return 1;

	if (is_home_change(dir))
	{
		cd_to_home(datash);
		return 1;
	}

	cd_to(datash);

	return 1;
}

		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}
