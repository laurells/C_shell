#include "hsh.h"

/**
 * get_line - funcion to read line from command into buffer
 *
 * Return: returns on success
 */

char *get_line(void)
{
	char *line = (char *) malloc(sizeof(char) * 1024);
	char ch;

	int position = 0, buffersize = 1024;

	if (!line)
	{
		printf("\nBuffer Allocation Error.");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		ch = getchar();
		if (ch == EOF || ch == '\n')
		{
			line[position] = '\0';
			return (line);
		}
		else
		{
			line[position] = ch;
		}
		position++;

		if (position >= buffersize)
		{
			buffersize += 1024;
			line = realloc(line, sizeof(char) * buffersize);
			if (!line)
			{
				printf("\nBuffer Allocation Error");
				exit(EXIT_FAILURE);
			}
		}
	}
}

int main(int argc, char **argv)
{
	if (argc == 1)
		shell_interact();
	else if (argc == 2)
		shell_script(argv[1]);
	else
		printf("\nInvalid Number of Arguments");

	return (EXIT_SUCCESS);
}
