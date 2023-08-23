#include "monty.h"

/**
 * handleOpcodePall - function that prints all the elements of the stack
 * @stack: input stack
 * @line_number: line number
 * Return: void
 */
void handleOpcodePall(StackN_t **stack, unsigned int line_number)
{
	UNUSED(line_number);

	if (!stack || !*stack)
		return;

	print_list(*stack);
}

/**
 * handleOpcodePint - function that prints the top element of the stack
 * @stack: input stack
 * @line_number: line number
 * Return: void
 */
void handleOpcodePint(StackN_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		empty_stack_err(line_number, execution_env.tokenized_str[0]);
		free_all_and_exit();
	}

	printf("%d\n", (*stack)->n);
}

/**
 * handleOpcodePop - function that removes the top element of the stack
 * @stack: input stack
 * @line_number: line number
 * Return: void
 */
void handleOpcodePop(StackN_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		empty_stack_err(line_number, execution_env.tokenized_str[0]);
		free_all_and_exit();
	}

	delete_first(stack);
}

/**
 * handleOpcodeNop - function that does nothing
 * @stack: input stack
 * @line_number: line number
 * Return: void
 */
void handleOpcodeNop(StackN_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}

/**
 * handleOpcodePush - function that pushes an element to the stack
 * @stack: input stack
 * @line_number: line number
 * Return: void
 */
void handleOpcodePush(StackN_t **stack, unsigned int line_number)
{
	int i;
	int number;
	char *opcode = execution_env.tokenized_str[0];
	char *argument = execution_env.tokenized_str[1];

	if (!execution_env.tokenized_str[1])
		push_non_integer(line_number, opcode);

	for (i = 0; argument[i]; i++)
	{
		if (!isdigit(argument[i]) && argument[0] != '-')
			push_non_integer(line_number, opcode);
	}

	number = atoi(argument);

	if (execution_env.mode == STACK_MODE)
		append_first(stack, number);
	else if (execution_env.mode == QUEUE_MODE)
		append_end(stack, number);
}
