#include "monty.h"

ExecutionEnvironment execution_env = ENVIRONMENT_INITIALIZER;

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: execute_operations function
*/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		usage_err();
	}

	return (execute_operations(argv[1]));
}
