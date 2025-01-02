#include "monty.h"

/**
 * errorr - Prints appropiate error messages determined by their error code.
 * @error_code: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void errorr(int error_code, ...)
{
	va_list list;
	char *opcode;
	int ln_no;

	va_start(list, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(list, char *));
			break;
		case 3:
			ln_no = va_arg(list, int);
			opcode = va_arg(list, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", ln_no, opcode);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(list, int));
			break;
		default:
			break;
	}
	freeNods();
	exit(EXIT_FAILURE);
}
