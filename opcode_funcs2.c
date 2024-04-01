#include "monty.h"

/**
 * add - adds top two elements of stack
 * @stack: pointer to stack
 * @line_number: line where add is called
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_1, *temp_2;

	(void) stack;

	if (arguments->stack_len < 2)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	temp_1 = arguments->head;
	temp_2 = temp_1->next;

	temp_2->n = temp_1->n + temp_2->n;
	delete_top();
	arguments->stack_len -= 1;
}

/**
 * nop - doesn't do anything
 * @stack: pointer to stack
 * @line_number: line where nop is called
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
