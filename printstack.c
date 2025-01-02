#include "monty.h"

/**
 * prnt_stck - Adds a node to the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @ln_no: line number of  the opcode.
 */
void prnt_stck(stack_t **stck, unsigned int ln_no)
{
	stack_t *temp;

	(void) ln_no;
	if (stck == NULL)
		exit(EXIT_FAILURE);
	temp = *stck;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
