#include "monty.h"

/**
 * handleOpcodePstr - function that prints the top element of the stack
 * @stack: input stack
 * @line_number: line number
 * Return: void
 */
void handleOpcodePstr(StackN_t **stack, unsigned int line_number)
{
	StackN_t *current = *stack;

	UNUSED(line_number);

	while (current)
	{
		if (current->n == 0 || !isascii(current->n))
			break;
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}

/**
 * handleOpcodePchar - function that prints the top element of the stack
 * @stack: input stack
 * @line_number: line number
 * Return: void
 */
void handleOpcodePchar(StackN_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		empty_stack_err(line_number, execution_env.tokenized_str[0]);
	}

	if (!isascii((*stack)->n))
	{
		ascii_err(line_number, execution_env.tokenized_str[0]);
	}

	printf("%c\n", (*stack)->n);
}
