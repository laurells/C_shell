#include "hsh.h"

void print_env(char **env)
{
	for (unsigned int i = 0; env[i] != NULL; ++i)
		printf("%s\n", env[i]);
}
