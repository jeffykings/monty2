#include "monty.h"

/**
 * opn_fle - opens a file
 * @fileOFname: the file namepath
 * Return: void
 */

void opn_fle(char *fileOFname)
{
	FILE *filedirector = fopen(fileOFname, "r");

	if (fileOFname == NULL || filedirector == NULL)
		errorr(2, fileOFname);

	rd_fle(filedirector);
	fclose(filedirector);
}


/**
 * rd_fle - reads a file
 * @filedirector: pointer to file descriptor
 * Return: void
 */

void rd_fle(FILE *filedirector)
{
	int ln_no, frmt = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (ln_no = 1; getline(&buffer, &len, filedirector) != -1; ln_no++)
	{
		frmt = ln_parse(buffer, ln_no, frmt);
	}
	free(buffer);
}
