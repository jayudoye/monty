#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack
 * (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct arg_s - hold variables
 * @stream: file that connects to the stream from file
 * @line: line of text read from @stream
 * @line_number: track current line num
 * @tokens: used to store tokens from line
 * @no_tokens: number of tokens created
 * @instruction: valid instructions
 * @head: first node/ top of stack
 */

typedef struct arg_s
{
	FILE *stream;
	char *line;
	unsigned int line_number;
	char **tokens;
	int no_tokens;
	instruction_t *instruction;
	stack_t *head;
} arg_t;

extern arg_t *arguments;

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
int dprintf(int fd, const char *format, ...);
FILE *fdopen(int fd, const char *mode);


/* interpreter functions*/
void validate_args(int argc);
void initialize_args(void);
void malloc_failed(void);
void stream_failed(char *filename);
void get_stream(char *filename);
void tokens(void);
void get_opcode(void);
void free_tokens(void);
void close_stream(void);
void run_opcode(void);
void free_args(void);
int is_num(char *s);
void free_head(void);
void free_stack(stack_t *head);
void invalid_opcode(void);
void free_all_args(void);

/* stack opcode functions*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
stack_t *push(stack_t **head, const int n);
size_t print_stack(const stack_t *h);
void free_stack(stack_t *head);
int delete_at_index(stack_t **head, unsigned int index);
size_t stack_len(const stack_t *h);

#endif
