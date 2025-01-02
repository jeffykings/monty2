#include "monty.h"

/**
 * add2queue - Adds a node to the queue.
 * @newNod: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void add2queue(stack_t **newNod, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (newNod == NULL || *newNod == NULL)
		exit(EXIT_FAILURE);
	if (Header == NULL)
	{
		Header = *newNod;
		return;
	}
	temp = Header;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *newNod;
	(*newNod)->prev = temp;

}
