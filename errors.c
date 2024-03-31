#include "monty.h"

/**
 * malloc_failed - handles when malloc fails to
 * allocate memory
 *
 */

void malloc_failed(void)
{
	dprintf(2, "Error: malloc failed\n");
	free_args();
	exit(EXIT_FAILURE);
}


/**
 * invalid_opcode - handles unknown opcode error
 *
 */

void invalid_opcode(void)
{
	dprintf(2, "L%d: unknown instruction %s\n",
			arguments->line_number, arguments->tokens[0]);
	free_all_args();
	exit(EXIT_FAILURE);
}
