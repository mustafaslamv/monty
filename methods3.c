#include "monty.h"

/**
 * handleOpcodeRotr - function that rotates the stack
 * @stack: input stack
 * @line_number: line number
 * Return: void
 */
void handleOpcodeRotr(StackN_t **stack, unsigned int line_number)
{
	StackN_t *current_node;
	int prev_node_value, tmp;

	UNUSED(line_number);

	if (!stack || !*stack)
		return;

	tmp = (*stack)->n;
	current_node = (*stack)->next;
	while (current_node)
	{
		prev_node_value = tmp;
		tmp = current_node->n;
		current_node->n = prev_node_value;
		current_node = current_node->next;
	}
	(*stack)->n = tmp;
}

/**
 * handleOpcodeSwap - function that swaps the top two elements of the stack
 * @stack: input stack
 * @line_number: line number
 * Return: void
 */
void handleOpcodeSwap(StackN_t **stack, unsigned int line_number)
{
	int tmp;

	if (get_list_len(*stack) < 2)
	{
		twoElements_err(line_number);
	}

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

/**
 * handleOpcodeRotl - function that rotates the stack
 * @stack: input stack
 * @line_number: line number
 * Return: void
 */
void handleOpcodeRotl(StackN_t **stack, unsigned int line_number)
{
	StackN_t *current_node;
	int top_value;

	UNUSED(line_number);

	if (!stack || !*stack)
		return;

	top_value = (*stack)->n;
	current_node = *stack;
	while (current_node->next)
	{
		current_node->n = current_node->next->n;
		current_node = current_node->next;
	}
	current_node->n = top_value;
}
