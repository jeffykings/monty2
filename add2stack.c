#include "monty.h"

/**
 * append_to_stack - Adds a node to the stack.
 * @newNd: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void append_to_stack(stack_t **newNd, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (newNd == NULL || *newNd == NULL)
		exit(EXIT_FAILURE);
	if (Header == NULL)
	{
		Header = *newNd;
		return;
	}
	temp = Header;
	Header = *newNd;
	Header->next = temp;
	temp->prev = Header;
}
