#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define UNUSED(x) (void)(x)
#define SPACE " "
#define MAX_TOKEN_COUNT 3
#define COMMENT '#'
#define ENVIRONMENT_INITIALIZER { NULL, NULL, NULL, NULL, 0 }
#define STACK "stack"
#define QUEUE "queue"

/**
 * enum Mode - stack or queue
 * @STACK_MODE: stack
 * @QUEUE_MODE: queue
*/
enum Mode
{
	STACK_MODE = 0,
	QUEUE_MODE = 1
};

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node
 * for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} StackN_t;

/**
 * struct instruction_s - opcode and function pointer
 * @opcode: opcode
 * @f: function
 * Description: opcode and function
 * for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(StackN_t **stack, unsigned int line_number);
} OpcodeFunctionPair;

/**
 * struct execution_env - execution environment
 * @stack: stack
 * @line_buffer: line buffer
 * @file_pointer: file pointer
 * @tokenized_str: tokenized string
 * @mode: mode
 * Description: execution environment
 * for stack, queues, LIFO, FIFO
*/
typedef struct execution_env
{
	StackN_t *stack;
	char **tokenized_str, *line_buffer;
	FILE *file_pointer;
	int mode;
} ExecutionEnvironment;

extern ExecutionEnvironment execution_env;

void (*getOpCFunc(char *opcode))(StackN_t **stack, unsigned int line_number);
void update_mode(char *opcode);

void usage_err(void);
void open_err(char *file_name);
void malloc_err(void);

void invalid_instruct_err(unsigned int line_number);
void twoElements_err(unsigned int line_number);

void empty_stack_err(unsigned int line_number, char *opcode);
void zero_division(unsigned int line_number);
void ascii_err(unsigned int line_number, char *opcode);
void push_non_integer(unsigned int line_number, char *opcode);

void print_list(const StackN_t *head);
size_t get_list_len(const StackN_t *head);
StackN_t *append_first(StackN_t **head, int n);
StackN_t *get_last_node(StackN_t **head);
StackN_t *append_end(StackN_t **head, int n);
StackN_t *delete_first(StackN_t **head);

void handleOpcodePush(StackN_t **stack, unsigned int line_number);
void handleOpcodePall(StackN_t **stack, unsigned int line_number);
void handleOpcodePint(StackN_t **stack, unsigned int line_number);
void handleOpcodePop(StackN_t **stack, unsigned int line_number);
void handleOpcodeNop(StackN_t **stack, unsigned int line_number);

void handleOpcodeAdd(StackN_t **stack, unsigned int line_number);
void handleOpcodeSub(StackN_t **stack, unsigned int line_number);
void handleOpcodeDiv(StackN_t **stack, unsigned int line_number);
void handleOpcodeMul(StackN_t **stack, unsigned int line_number);
void handleOpcodeMod(StackN_t **stack, unsigned int line_number);

void handleOpcodeSwap(StackN_t **stack, unsigned int line_number);
void handleOpcodeRotl(StackN_t **stack, unsigned int line_number);
void handleOpcodeRotr(StackN_t **stack, unsigned int line_number);

void handleOpcodePchar(StackN_t **stack, unsigned int line_number);
void handleOpcodePstr(StackN_t **stack, unsigned int line_number);

void free_linked_list(StackN_t *head);
void free_tokenized_string(char **tokenized_str);
void free_all_and_exit(void);

FILE *open_file(char *file_name);
ssize_t read_line(size_t *buffer_size);
char **tokenize_string(const char *delim);
int execute_operations(char *file_name);
int check_mode_comment(char **tokenized_str);

#endif
