#include "monty.h"

/**
 * delete_first - function that deletes the first node
 * @head: head
 * Return: NULL if head is NULL | head
*/
StackN_t *delete_first(StackN_t **head)
{
	StackN_t *temp = *head;

	if (*head == NULL)
		return (NULL);

	*head = (*head)->next;
	if (*head != NULL)
		(*head)->prev = NULL;

	temp->next = NULL;
	free(temp);

	return (*head);
}

/**
 * print_list - function that prints the list
 * @head: head
 * Return: void
*/
void print_list(const StackN_t *head)
{
	const StackN_t *current;

	if (!head)
		return;

	current = head;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
