#include "monty.h"

/**
 * errorrExtra - handles errors.
 * @error_code: The error codes are the following:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void errorrExtra(int error_code, ...)
{
	va_list list;
	char *opcode;
	int ln_no;

	va_start(list, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(list, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(list, int));
			break;
		case 8:
			ln_no = va_arg(list, unsigned int);
			opcode = va_arg(list, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", ln_no, opcode);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(list, unsigned int));
			break;
		default:
			break;
	}
	freeNods();
	exit(EXIT_FAILURE);
}
