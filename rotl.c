#include "monty.h"

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotl(stack_t **stck, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		return;

	temp = *stck;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stck;
	(*stck)->prev = temp;
	*stck = (*stck)->next;
	(*stck)->prev->next = NULL;
	(*stck)->prev = NULL;
}
