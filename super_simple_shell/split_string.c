#include "main.h"

/**
 *word_count - counts the number of words in a string
 *@str: the string to count words from
 *
 *Return: the number of words in str
 */

int word_count(char *str)
{
	int w_count = 0, i = 0;

	while (str[i])
	{
		if (str[i] == ' ' && str[i - 1] != ' ')
			w_count++;
		i++;
	}
	w_count++;
	return (w_count);
}


/**
 *split_string - splits a string into an array of individual words
 *@str: the string to split into words
 *@delim: the delimiter to split str with
 *
 *Return: pointer to an array of words from str
 */

char **split_string(char *str, char *delim)
{
	char *token;
	char **string_array;
	int index = 0, w_count = 0;

	w_count = word_count(str);

	string_array = malloc(sizeof(char *) * (w_count + 1));
	if (string_array == NULL)
		return (NULL);

	token = strtok(str, delim);

	while (token != NULL)
	{
		/*string_array[index] = malloc(sizeof(char) * strlen(token));
		if (string_array[index] == NULL)
		{
			for (; index >= 0; index--)
				free(string_array[index]);
			free(string_array);
			return (NULL);
			}*/
		string_array[index] = token;
		token = strtok(NULL, delim);
		index++;
	}
	return (string_array);
}
