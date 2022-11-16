#include "hsh.h"

/**
 * shell_script - shell called arguments
 *
 * @filename: file size
 *
 * Return: returns 1 on success
 */

int shell_script(char filename[])
{
	FILE *fptr;

	char line[200];

	char **args;

	fptr = fopen(filename, "r");

	printf("Received Script. Opening %s", filename);

	if (fptr == NULL)
	{
		printf("\nUnable to open file.");
		return (1);
	}
	else
	{
		printf("\nFile Opened. Parsing. Parsed commands displayed first.");
		while (fgets(line, sizeof(line), fptr) != NULL)
		{
			printf("\n%s", line);
			args = _split_line(line);
			exec_shell(args);
		}
	}
	free(args);
	fclose(fptr);
	return (1);
}
