#include "monty.h"

/**
 * free_linked_list - function that frees the linked list
 * @head: head
 * Return: void
 */
void free_linked_list(StackN_t *head)
{
	StackN_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * free_all_and_exit - function that frees all the memory
 * Return: void
 */
void free_all_and_exit(void)
{
	if (execution_env.stack)
		free_linked_list(execution_env.stack);

	if (execution_env.tokenized_str)
		free_tokenized_string(execution_env.tokenized_str);

	if (execution_env.line_buffer)
		free(execution_env.line_buffer);

	if (execution_env.file_pointer)
		fclose(execution_env.file_pointer);

	exit(EXIT_FAILURE);
}

/**
 * free_tokenized_string - function that frees the tokenized string
 * @tokenized_str: tokenized string
 * Return: void
 */
void free_tokenized_string(char **tokenized_str)
{
	int idx;

	for (idx = 0; tokenized_str[idx]; idx++)
		free(tokenized_str[idx]);

	free(tokenized_str);
}
