#include "monty.h"

/**
 * push - pushes an integer onto the stack
 * @stack: pointer to stack
 * @line_number: line number where push is called
 *
 */

void push(stack_t **stack, unsigned int line_number)
{
	if (arguments->no_tokens <= 1 || !(is_num(arguments->tokens[1])))
	{
		free_args();
		dprintf(2, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
		malloc_failed();
	(*stack)->next = NULL;
	(*stack)->prev = NULL;
	(*stack)->n = atoi(arguments->tokens[1]);

	if (arguments->head != NULL)
	{
		(*stack)->next = arguments->head;
		arguments->head->prev = *stack;
	}
	arguments->head = *stack;
	arguments->stack_len += 1;
}

/**
 * pall - prints all the elements in a stack
 * @stack: pointer to stack
 * @line_number: line number where pall is called
 *
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	(void) stack;

	if (arguments->head == NULL)
		return;
	temp = arguments->head;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}

}

/**
 * pint - prints the top element of the stack
 * @stack: pointer to stack
 * @line_number: line number where pint is called
 */

void pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;

	if (arguments->head == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty", line_number
		       );
		free_all_args();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", arguments->head->n);
}

/**
 * pop - deletes top element in a stack
 * @stack: pointer to stack
 * @line_number: line where pop is called
 */

void pop(stack_t **stack, unsigned int line_number)
{
	(void) stack;

	if (arguments->head == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	delete_top();
	arguments->stack_len -= 1;
}


/**
 * swap - swaps the two top elements of the  stack
 * @stack: pointer to stack
 * @line_number: line where swap is called
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_1, *temp_2;

	(void) stack;

	if (arguments->stack_len < 2)
	{
		dprintf(2, "L%d: can't swap, stack too short", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	temp_1 = arguments->head;
	temp_2 = temp_1->next;
	temp_1->next = temp_2->next;
	if (temp_1->next)
		temp_1->next->prev = temp_1;

	temp_2->next = temp_1;
	temp_1->prev = temp_2;
	temp_2->prev = NULL;
	arguments->head = temp_2;
}
