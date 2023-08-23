#include "monty.h"

/**
 * handleOpcodeMod - function that modifies the top element of the stack
 * @stack: input stack
 * @line_number: line number
 * Return: void
 */
void handleOpcodeMod(StackN_t **stack, unsigned int line_number)
{
	int value;

	if (get_list_len(*stack) < 2)
	{
		twoElements_err(line_number);
	}

	if ((*stack)->n == 0)
	{
		zero_division(line_number);
	}

	value = (*stack)->n;
	delete_first(stack);
	(*stack)->n %= value;
}

/**
 * handleOpcodeMul - function that multiplies the top element of the stack
 * @stack: input stack
 * @line_number: line number
 * Return: void
 */
void handleOpcodeMul(StackN_t **stack, unsigned int line_number)
{
	int value;

	if (get_list_len(*stack) < 2)
	{
		twoElements_err(line_number);
	}

	value = (*stack)->n;
	delete_first(stack);
	(*stack)->n *= value;
}

/**
 * handleOpcodeSub - function that subtracts the top element of the stack
 * @stack: input stack
 * @line_number: line number
 * Return: void
 */
void handleOpcodeSub(StackN_t **stack, unsigned int line_number)
{
	int value;

	if (get_list_len(*stack) < 2)
	{
		twoElements_err(line_number);
	}

	value = (*stack)->n;

	delete_first(stack);
	(*stack)->n -= value;
}

/**
 * handleOpcodeDiv - function that divides the top element of the stack
 * @stack: input stack
 * @line_number: line number
 * Return: void
 */
void handleOpcodeDiv(StackN_t **stack, unsigned int line_number)
{
	int value;

	if (get_list_len(*stack) < 2)
	{
		twoElements_err(line_number);
	}
	if ((*stack)->n == 0)
	{
		zero_division(line_number);
	}

	value = (*stack)->n;
	delete_first(stack);
	(*stack)->n /= value;
}

/**
 * handleOpcodeAdd - function that adds the top element of the stack
 * @stack: input stack
 * @line_number: line number
 * Return: void
 */
void handleOpcodeAdd(StackN_t **stack, unsigned int line_number)
{
	int value;

	if (get_list_len(*stack) < 2)
	{
		twoElements_err(line_number);
	}

	value = (*stack)->n;
	delete_first(stack);
	(*stack)->n += value;
}
