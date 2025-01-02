#include "monty.h"

/**
 * prntstr - Prints a string.
 * @stck: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void prntstr(stack_t **stck, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *temp;

	if (stck == NULL || *stck == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stck;
	while (temp != NULL)
	{
		ascii = temp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		temp = temp->next;
	}
	printf("\n");
}
