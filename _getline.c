#include "main.h"

/**
 *_getline - gets line of input from the standard input
 *
 *Return: pointer to the string retrieved from stdin
 */

char *_getline(void)
{
	char *line = NULL;
	size_t size = 0;

	if (getline(&line, &size, stdin) == -1)
	{
		free(line);
		return (NULL);
	}

	if (line[strlen(line) - 1] == '\n')
		line[strlen(line) - 1] = '\0';

	return (line);
}
