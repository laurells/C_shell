#include "main.h"

/**
 *exit_shell - exits the simple_shell
 *@input: the "exit" keyword that invokes this function
 *
 *Return: void
 */

void exit_shell(char *input)
{
	free(input);
	exit(EXIT_SUCCESS);
}


/**
 *print_env - prints the environment variables
 *@input: the "env" keyword that invokes this function
 *
 *Return: void
 */

void print_env(char *input)
{
	int i = 0;

	while (environ[i])
	{
		puts(environ[i]);
		i++;
	}
	free(input);
}


/**
 *execute_builtin - executes a builtin fucntion
 *@input: the builtin to execute
 *
 *Return: 0 on sucess, otherwise -1
 */

