#include "monty.h"

/**
 * node_at_index - get node at the given index
 * @head: pointer to the head node
 * @index: the position of the node in the list
 * Return: node at the given index if it exists else NULL
 */
stack_t *node_at_index(stack_t *head, unsigned int index)
{
	stack_t *current = head;
	unsigned int i = 0;

	while (current && i < index)
	{
		current = current->next;
		i++;
	}

	return (current);
}


/**
 * insert_at_end - inserts a node at the end of queue
 * @head: pointer to the head node
 * @n: value of the new node
 * Return: the newly inserted node
 */
stack_t *insert_at_end(stack_t **head, const int n)
{
	stack_t *current = *head;
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
		return (NULL);

	new->n  = n;

	current = node_at_index(*head, stack_len(*head) - 1);

	if (current == NULL)
		*head = new;

	if (current != NULL)
	{
		current->next = new;
		new->prev = current;
	}

	return (new);
}

/**
 * delete_at_index - deltes a node in a doubly linked list
 * at a given index
 * @head: double pointer to the list
 * @index: index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_at_index(stack_t **head, unsigned int index)
{
	stack_t *current = *head;
	unsigned int i = 0;

	if (*head == NULL || stack_len(current) < index + 1)
		return (-1);

	if (!index)
	{
		(*head) = current->next;
		if (current->next)
			current->next->prev = NULL;
		current->next = NULL;
		free(current);
		return (1);
	}

	while (i < index)
	{
		current = current->next;
		i++;
	}

	current->prev->next = current->next;
	if (current->next)
		current->next->prev = current->prev;
	free(current);

	return (1);
}
