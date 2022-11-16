#include "main.h"

/**
 *create_process - creates a child process and executes a program
 *@arguments: the arguments to execute program with
 *
 *Return: 0 on success, otherwise -1
 */

int create_process(char **arguments)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error: ");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(arguments[0], arguments, NULL) == -1)
		{
			perror("Error: ");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
