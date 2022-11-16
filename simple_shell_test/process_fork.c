#include "hsh.h"

/**
 * _shell_launch - function to create child preocess
 * and run commands.
 * @args: arguments
 *
 * Return: returns 1
 */

int _shell_launch(char **args)
{
	pid_t pid;

	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("$ ");
		}
	exit(EXIT_FAILURE);
	}

	else if (pid < 0)
	{
		perror("$ ");
	}
	else
		wait(&status);

	return (0);
}
