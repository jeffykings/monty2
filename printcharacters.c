#include "monty.h"

/**
 * prntchar - Prints the Ascii value.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @ln_no: Interger representing the line number of of the opcode.
 */
void prntchar(stack_t **stck, unsigned int ln_no)
{
	int ascii;

	if (stck == NULL || *stck == NULL)
		err_strn(11, ln_no);

	ascii = (*stck)->n;
	if (ascii < 0 || ascii > 127)
		err_strn(10, ln_no);
	printf("%c\n", ascii);
}
