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
 * pint
*/