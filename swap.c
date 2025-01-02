#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @ln_no: Interger representing the line number of of the opcode.
 */
void swap(stack_t **stck, unsigned int ln_no)
{
	stack_t *temp;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		errorrExtra(8, ln_no, "swap");
	temp = (*stck)->next;
	(*stck)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stck;
	temp->next = *stck;
	(*stck)->prev = temp;
	temp->prev = NULL;
	*stck = temp;
}
