#include "monty.h"

/**
 * invalid_instruct_err - function that prints invalid instruction
 * @line_number: line number
 * Return: void
 */
void invalid_instruct_err(unsigned int line_number)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number,
			execution_env.tokenized_str[0]);
	free_all_and_exit();
}

/**
 * twoElements_err - function that prints two elements error
 * @line_number: line number
 * Return: void
 */
void twoElements_err(unsigned int line_number)
{
	char *mode;

	if (execution_env.mode == STACK_MODE)
		mode = STACK;
	else
		mode = QUEUE;

	fprintf(stderr, "L%d: can't %s, %s too short\n", line_number,
			execution_env.tokenized_str[0], mode);
	free_all_and_exit();
}
