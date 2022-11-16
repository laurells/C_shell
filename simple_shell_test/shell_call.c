#include "hsh.h"

/**
 * shell_interact - call shell interactively
 *
 * Return: return 1 on success
 */

int shell_interact(void)
{
	char *line;
	char **args;
	int QUIT = 0;

	while (QUIT == 0)
	{
		printf("$ ");
		line = get_line();
		args = _split_line(line);
		exec_shell(args);
		free(line);
		free(args);
	}
	return (1);
}
