#include "monty.h"

/**
 * s_push - pushes a value to the stack
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void s_push(stack_t **stack, unsigned int line_number)
{
	int value;

	if (env.arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	value = atoi(env.arg);

	if (value == 0 && strncmp(env.arg, "0", 1) != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	push(stack, value);
}

/**
 * pop - removes the top value from the stack
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	delete_at_index(stack, 0);
}

/**
 * pint - prints the topmost element of the stack
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't print, stack is empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pall - prints all the elements of the stack starting from the top
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_stack(*stack);
}


/**
 * swap - swaps the top two elements
 * @stack: a pointer to the stack
 * @line_number: position of the opcode in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{

	stack_t *second;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);

	}
	second = (*stack)->next;

	(*stack)->next = second->next;
	if (second->next != NULL)
		second->next->prev = *stack;
	second->next = *stack;
	second->prev = NULL;
	(*stack)->prev = second;

	(*stack) = second;
}
