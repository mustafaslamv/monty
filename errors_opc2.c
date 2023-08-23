#include "monty.h"

/**
 * empty_stack_err - function that prints empty stack
 * @line_number: line number
 * @opcode: opcode
 * Return: void
*/
void empty_stack_err(unsigned int line_number, char *opcode)
{
	char *mode;

	if (execution_env.mode == STACK_MODE)
		mode = STACK;
	else
		mode = QUEUE;

	if (!strcmp(opcode, "pint") || !strcmp(opcode, "pchar"))
		fprintf(stderr, "L%u: can't %s, %s empty\n", line_number, opcode, mode);
	else if (strcmp(opcode, "pop") == 0)
		fprintf(stderr, "L%u: can't %s an empty %s\n", line_number, opcode, mode);
	free_all_and_exit();
}

/**
 * zero_division - function that prints division by zero
 * @line_number: line number
 * Return: void
*/
void zero_division(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	free_all_and_exit();
}

/**
 * push_non_integer - function that prints push non integer
 * @line_number: line number
 * @opcode: opcode
 * Return: void
*/
void push_non_integer(unsigned int line_number, char *opcode)
{
	fprintf(stderr, "L%d: usage: %s integer\n", line_number, opcode);
	free_all_and_exit();
}

/**
 * ascii_err - function that prints ascii out of range
 * @line_number: line number
 * @opcode: opcode
 * Return: void
*/
void ascii_err(unsigned int line_number, char *opcode)
{
	fprintf(stderr, "L%u: can't %s, value out of range\n", line_number, opcode);
	free_all_and_exit();
}
