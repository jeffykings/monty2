#include "monty.h"

/**
 * push - Adds a node to the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @ln_no: interger represe61062fb351e055936994nting the line number of
 * the opcode.
 */
void push(stack_t **stck, unsigned int ln_no)
{
	stack_t *temp;

	if (stck == NULL || *stck == NULL)
		errorrExtra(7, ln_no);

	temp = *stck;
	*stck = temp->next;
	if (*stck != NULL)
		(*stck)->prev = NULL;
	free(temp);
}
