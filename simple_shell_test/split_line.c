#include "hsh.h"

/**
 * _split_line - split enter string into commands
 * @line: input from stin
 * Return: return command
 */

char **_split_line(char *line)
{
	char **tokens = (char **)malloc(sizeof(char *) * 64);

	char *token;

	char delim[10] = " \t\n\r\a";
	int position = 0, buffersize = 64;

	if (!tokens)
	{
		printf("\nBuffer Allocation Error.");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, delim);

	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= buffersize)
		{
			buffersize += 64;
			line = realloc(line, buffersize * sizeof(char *));
			if (!line)
			{
			printf("\nBuffer Allocation Error.");
			exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, delim);
	}
	tokens[position] = NULL;
	return (tokens);
}
