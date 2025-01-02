#include "monty.h"

/**
 * freeNods - Frees nodes in the stack.
 */
void freeNods(void)
{
	stack_t *temp;

	if (Header == NULL)
		return;

	while (Header != NULL)
	{
		temp = Header;
		Header = Header->next;
		free(temp);
	}
}
