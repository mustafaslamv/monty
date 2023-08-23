#include "monty.h"

/**
 * open_file - function that opens a file
 * @file_name: file name
 * Return: file_pointer
 */
FILE *open_file(char *file_name)
{
	FILE *file_pointer;

	file_pointer = fopen(file_name, "r");

	if (file_pointer == NULL)
	{
		open_err(file_name);
	}

	return (file_pointer);
}

/**
 * tokenize_string - function that tokenizes a string
 * @delim: delimiter
 * Return: tokenized_str
 */
char **tokenize_string(const char *delim)
{
	char *token = NULL;
	char **tokenized_str = NULL;
	int idx = 0;

	tokenized_str = malloc(sizeof(char *) * MAX_TOKEN_COUNT);
	if (tokenized_str == NULL)
	{
		malloc_err();
	}

	token = strtok(execution_env.line_buffer, delim);
	while (idx < MAX_TOKEN_COUNT - 1 && token != NULL)
	{
		tokenized_str[idx] = malloc(strlen(token) + 1);
		if (tokenized_str[idx] == NULL)
		{
			malloc_err();
		}

		strcpy(tokenized_str[idx], token);
		token = strtok(NULL, delim);
		idx++;
	}

	tokenized_str[idx] = NULL;
	return (tokenized_str);
}

/**
 * read_line - function that reads a line
 * @buffer_size: buffer size
 * Return: characters variable
 */
ssize_t read_line(size_t *buffer_size)
{
	ssize_t characters;

	characters = getline(&execution_env.line_buffer,
						 buffer_size,
						 execution_env.file_pointer);

	return (characters);
}
