#include "monty.h"

/**
 * update_mode - function that updates the mode
 * @opcode: opcode
 * Return: void
 */
void update_mode(char *opcode)
{
	if (!strcmp(opcode, "stack"))
	{
		execution_env.mode = STACK_MODE;
	}
	else if (!strcmp(opcode, "queue"))
	{
		execution_env.mode = QUEUE_MODE;
	}
}
