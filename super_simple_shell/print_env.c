#include "main.h"

/**
 *print_env - prints the environment
 *@env: pointer to the environment to be printed
 *
 *Return: void
 */

void print_env(char **env)
{
	unsigned int i = 0;

	while (env[i])
	{
		puts(env[i]);
		i++;
	}
}
