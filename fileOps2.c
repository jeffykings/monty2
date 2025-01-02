#include "monty.h"

/**
 * ln_parse - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @ln_no: line number
 * @frmt:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int ln_parse(char *buffer, int ln_no, int frmt)
{
	char *opcode, *vlu;
	const char *delim = "\n ";

	if (buffer == NULL)
		errorr(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (frmt);
	vlu = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find(opcode, vlu, ln_no, frmt);
	return (frmt);
}

/**
 * find - find the appropriate function for the opcode
 * @opcode: opcode
 * @vlu: argument of opcode
 * @frmt:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find(char *opcode, char *vlu, int ln, int frmt)
{
	int i;
	int flag;

	instruction_t list_of_fun[] = {
		{"push", push},
		{"pall", prnt_stck},
		{"pop", pop},
		{"nop", Donothing},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divNode},
		{"mul", mul},
		{"mod", mod},
		{"pchar", prntchar},
		{"pstr", prntstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; list_of_fun[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, list_of_fun[i].opcode) == 0)
		{
			fun_call(list_of_fun[i].f, opcode, vlu, ln, frmt);
			flag = 0;
		}
	}
	if (flag == 1)
		errorr(3, ln, opcode);
}


/**
 * fun_call - Calls the required function.
 * @fun: Pointer to the function that is about to be called.
 * @opcode: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @frmt: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void fun_call(op_func fun, char *opcode, char *val, int ln, int frmt)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			errorr(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				errorr(5, ln);
		}
		node = crt_Node(atoi(val) * flag);
		if (frmt == 0)
			fun(&node, ln);
		if (frmt == 1)
			add2queue(&node, ln);
	}
	else
		fun(&Header, ln);
}
