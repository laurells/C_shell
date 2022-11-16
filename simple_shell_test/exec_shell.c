#include "hsh.h"

/**
 * exec_shell - exeute commands
 * @args: arguments
 *
 * Return: returns to process
 */

int exec_shell(char **args)
{
	int process, i;

	char *builtin_cmd[] = {"cd", "exit"};

	int (*builtin_func[]) (char **) = {&shell_cd, &shell_exit};

	if (args[0] == NULL)
	{
		return (1);
	}

	for (i = 0; i < _builtin(); i++)
	{
		if (strcmp(args[0], builtin_cmd[i]) == 0)
			return ((*builtin_func[i])(args));
	}
	process = _shell_launch(args);
	return (process);
}
