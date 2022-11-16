#include "hsh.h"

/**
 * _builtin - builtin command defination
 *
 * Return: returns number of builtin commands
 */

int _builtin(void)
{
	char *builtin_cmd[] = {"cd", "exit"};

	return (sizeof(builtin_cmd) / sizeof(char *));
}

/**
 * shell_cd - built in command definiton
 * @args: arguments
 *
 * Return: returns 1
 */

int shell_cd(char **args)
{
	if (args[1] == NULL)
	{
		printf("$ expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("$ ");
		}
	}
	return (1);
}

/**
 * shell_exit - function for exit command
 *
 * Return: returns 0 on success
 */

int shell_exit(void)
{
	return (0);
