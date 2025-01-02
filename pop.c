#include "monty.h"

/**
 * pop - Prints the top node of the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @ln_no: Interger representing the line number of of the opcode.
 */
void pop(stack_t **stck, unsigned int ln_no)
{
	if (stck == NULL || *stck == NULL)
		errorrExtra(6, ln_no);
	printf("%d\n", (*stck)->n);
}
