#include "monty.h"

/**
 * mul - Adds the top two elements of the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @ln_no: Interger representing the line number of of the opcode.
 */
void mul(stack_t **stck, unsigned int ln_no)
{
	int sum;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)
		errorrExtra(8, ln_no, "mul");

	(*stck) = (*stck)->next;
	sum = (*stck)->n * (*stck)->prev->n;
	(*stck)->n = sum;
	free((*stck)->prev);
	(*stck)->prev = NULL;
}


/**
 * mod - Adds the top two elements of the stack.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @ln_no: Interger representing the line number of of the opcode.
 */
void mod(stack_t **stck, unsigned int ln_no)
{
	int sum;

	if (stck == NULL || *stck == NULL || (*stck)->next == NULL)

		errorrExtra(8, ln_no, "mod");


	if ((*stck)->n == 0)
		errorrExtra(9, ln_no);
	(*stck) = (*stck)->next;
	sum = (*stck)->n % (*stck)->prev->n;
	(*stck)->n = sum;
	free((*stck)->prev);
	(*stck)->prev = NULL;
}
