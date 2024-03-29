#include "monty.h"

/**
 * initialize_args - initializes a pointer to
 * arg_t struct
 */

void initialize_args(void)
{
	arguments = malloc(sizeof(arg_t));
	if (arguments == NULL)
		malloc_failed();

	arguments->instruction = malloc(sizeof(instruction_t));
	if (arguments->instruction == NULL)
		malloc_failed();

	arguments->stream = NULL;
	arguments->line = NULL;
	arguments->head = NULL;
	arguments->no_tokens = 0;
	arguments->line_number = 0;
	arguments->stack_len = 0;
}
