#include "monty.h"

/**
 * err_strn - handles errors.
 * @error_code: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void err_strn(int error_code, ...)
{
	va_list list;
	int ln_no;

	va_start(list, error_code);
	ln_no = va_arg(list, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", ln_no);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", ln_no);
			break;
		default:
			break;
	}
	freeNods();
	exit(EXIT_FAILURE);
}
