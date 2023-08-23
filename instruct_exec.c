#include "monty.h"

/**
 * getOpCFunc - function that gets the operation
 * @opcode: opcode
 * Return: function | NULL
*/
void (*getOpCFunc(char *opcode))(StackN_t **stack, unsigned int line_number)
{
	int idx;
	OpcodeFunctionPair instructions_arr[] = {
		{"push", handleOpcodePush},
		{"pall", handleOpcodePall},
		{"pint", handleOpcodePint},
		{"pop", handleOpcodePop},
		{"swap", handleOpcodeSwap},
		{"add", handleOpcodeAdd},
		{"nop", handleOpcodeNop},
		{"sub", handleOpcodeSub},
		{"div", handleOpcodeDiv},
		{"mul", handleOpcodeMul},
		{"mod", handleOpcodeMod},
		{"pchar", handleOpcodePchar},
		{"pstr", handleOpcodePstr},
		{"rotl", handleOpcodeRotl},
		{"rotr", handleOpcodeRotr},
		{NULL, NULL}
	};

	for (idx = 0; instructions_arr[idx].opcode; idx++)
		if (!strcmp(instructions_arr[idx].opcode, opcode))
			return (instructions_arr[idx].f);

	return (NULL);
}

/**
 * execute_operations - function that executes the operations
 * @file_name: file name
 * Return: EXIT_SUCCESS
*/
int execute_operations(char *file_name)
{
	ssize_t chars_number;
	size_t buffer_size = 0;
	unsigned int line_number = 0;
	char **tokenized_str;
	void (*opcode_func)(StackN_t **stack, unsigned int line_number);

	execution_env.file_pointer = open_file(file_name);

	while ((chars_number = read_line(&buffer_size)) != -1)
	{
		line_number++;
		execution_env.line_buffer[chars_number - 1] = '\0';
		execution_env.tokenized_str = tokenize_string(SPACE);
		tokenized_str = execution_env.tokenized_str;

		if (check_mode_comment(tokenized_str))
			continue;

		opcode_func = getOpCFunc(tokenized_str[0]);
		if (opcode_func == NULL)
		{
			invalid_instruct_err(line_number);
		}
		opcode_func(&execution_env.stack, line_number);

		free_tokenized_string(execution_env.tokenized_str);
	}

	free(execution_env.line_buffer);
	free_linked_list(execution_env.stack);
	fclose(execution_env.file_pointer);

	return (EXIT_SUCCESS);
}

/**
 * check_mode_comment - function that checks if the line is a comment
 * @tokenized_str: tokenized string
 * Return: 1 | 0
*/
int check_mode_comment(char **tokenized_str)
{
	if (tokenized_str[0] == NULL || tokenized_str[0][0] == COMMENT)
	{
		free_tokenized_string(execution_env.tokenized_str);
		return (1);
	}

	if (!strcmp(tokenized_str[0], STACK) || !strcmp(tokenized_str[0], QUEUE))
	{
		update_mode(tokenized_str[0]);
		free_tokenized_string(execution_env.tokenized_str);
		return (1);
	}

	return (0);
}
