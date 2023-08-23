#include "monty.h"

/**
 * get_list_len - function that gets the length of the list
 * @head: head
 * Return: size
*/
size_t get_list_len(const StackN_t *head)
{
	const StackN_t *current;
	size_t nodes_number = 0;

	if (!head)
		return (0);

	current = head;

	while (current != NULL)
	{
		current = current->next;
		nodes_number++;
	}

	return (nodes_number);
}

/**
 * append_first - function that adds a node at the beginning
 * @head: head
 * @n: number
 * Return: head
*/
StackN_t *append_first(StackN_t **head, const int n)
{
	StackN_t *new_node = malloc(sizeof(StackN_t));

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (!*head)
	{
		*head = new_node;
		return (*head);
	}

	(*head)->prev = new_node;
	*head = new_node;

	return (*head);
}

/**
 * get_last_node - function that gets the last node
 * @head: head
 * Return: last
*/
StackN_t *get_last_node(StackN_t **head)
{
	StackN_t *current = *head;

	while (current->next != NULL)
		current = current->next;

	return (current);
}

/**
 * append_end - function that adds a node at the end
 * @head: head
 * @n: number
 * Return: head
*/
StackN_t *append_end(StackN_t **head, const int n)
{
	StackN_t *new_node = malloc(sizeof(StackN_t));
	StackN_t *last;

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (!head || !*head)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (*head);
	}

	last = get_last_node(head);
	new_node->prev = last;
	last->next = new_node;

	return (*head);
}
