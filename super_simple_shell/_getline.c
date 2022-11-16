#include "main.h"

/**
 *_getline - gets line from stdin
 *
 *Return: a string gotten from user from stdin
 */

char *_getline(void)
{
	char *line = NULL;
	size_t size = 0;
	
	if (getline(&line, &size, stdin) == -1)
	{
		return (NULL);
	}

	if (line[strlen(line) - 1] == '\n')
		line[strlen(line) - 1] = '\0';

	return (line);
}
