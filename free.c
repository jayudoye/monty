#include "monty.h"

/**
 * free_tokens - frees the allocated memory for tokens
 *
 */

void free_tokens(void)
{
	int i = 0;

	if (arguments->tokens == NULL)
		return;

	while (arguments->tokens == NULL)
	{
		free(arguments->tokens[i]);
		i++;
	}
	free(arguments->tokens);
	arguments->tokens = NULL;
}

/**
 * free_args - frees memory allocated to
 * arguments pointer
 *
 */

void free_args(void)
{
	if (arguments == NULL)
		return;

	if (arguments->instruction)
	{
		free(arguments->instruction);
		arguments->instruction = NULL;
	}

	free_head();

	if (arguments->line)
	{
		free(arguments->line);
		arguments->line = NULL;
	}
	free(arguments);
}

/**
 * free_head - frees the head pointer
 *
 */

void free_head(void)
{
	if (arguments->head)
		free_stack(arguments->head);

	arguments->head = NULL;
}

/**
 * free_stack - free nodes in stack
 * @head: first node in stack
 *
 */

void free_stack(stack_t *head)
{
	if (head == NULL)
		return;

	if (head->next != NULL)
		free_stack(head->next);

	free(head);
}

/**
 * free_all_args - frees all allocated memory for
 * arguments pointer
 */

void free_all_args(void)
{
	close_stream();
	free_tokens();
	free_args();
}
