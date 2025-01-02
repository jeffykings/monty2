#include "monty.h"

/**
 * rotr - Rotates the last node of the stack to the top.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotr(stack_t **stck, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		return;

	temp = *stck;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stck;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stck)->prev = temp;
	(*stck) = temp;
}
