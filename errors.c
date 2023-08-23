#include "monty.h"

/**
 * open_err - function that opens a file
 * @file_name: file name
 * Return: void
 */
void open_err(char *file_name)
{
	fprintf(stderr, "Error: Can't open file %s\n", file_name);
	free_all_and_exit();
}

/**
 * usage_err - function that prints usage
 * Return: void
 */
void usage_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	free_all_and_exit();
}

/**
 * malloc_err - function that prints malloc error
 * Return: void
 */
void malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_all_and_exit();
}
