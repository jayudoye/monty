#include "monty.h"

/**
 * delete_top - deletes a node in a doubly linked list
 * at a given index
 *
 */

void delete_top(void)
{
	stack_t *temp = arguments->head;

	arguments->head = temp->next;
	free(temp);
}
