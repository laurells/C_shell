#include "main.h"

/**
 *getPATH - gets the list of directories in PATH
 *
 *Return: an array containing list of directories in PATH
 */

char **getPATH(void)
{
	char **path_dir;
	int i = 0, n = 0;
	size_t size = 1;
	char *token, *token2;

	while (environ[i])
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			token = strtok(environ[i], "=");
			break;
		}
		i++;
	}

	token = strtok(NULL, "=");

	path_dir = malloc(sizeof(char *) * (size + 1));
	if (!path_dir)
		return (NULL);

	token2 = strtok(token, ":");
	while (token2 != NULL)
	{
		path_dir[n] = token2;
		token2 = strtok(NULL, ":");
		size++;
		path_dir = realloc(path_dir, sizeof(char *) * size);
		n++;
	}

	return (path_dir);
}


/**
 *get_abs_pathname - gets the absolute pathname
 *                        of an existing shell executable
 *@argument: the name of executable to get absolute pathname for
 *
 *Return: absolute pathname of argument
*/

char *get_abs_pathname(char *argument)
{
	struct stat status;
	static char buffer[1024];
	int i, j, n;
	char **path_dir;

	if (argument[0] == '/' || argument[0] == '.')
	{
		if (stat(argument, &status) == -1)
			return (NULL);
		else
			return (argument);
	}

	path_dir = getPATH();
	for (i = 0; path_dir[i]; i++)
	{
		for (j = 0; path_dir[i][j]; j++)
		{
			buffer[j] = path_dir[i][j];
		}
		buffer[j] = '/';
		j++;
		for (n = 0; argument[n]; n++)
		{
			buffer[j] = argument[n];
			j++;
		}
		buffer[j] = '\0';
		if (stat(buffer, &status) == -1)
		{
			continue;
		}
		else
		{
			free(path_dir);
			return (buffer);
		}
	}
	free(path_dir);
	return (NULL);
}
