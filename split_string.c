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
		if (str[i] == ' ')
		{
			if (str[i + 1] != ' ' && str[i + 1] != '\0')
				w_count++;
			else if (i == 0)
				w_count++;
		}
		i++;
	}
	w_count++;
	return (w_count);
}

/**
 *split_string - splits a string into individual words
 *@str: the string to split
 *@delim: the delimiter to split str with
 *
 *Return: a pointer to an array of words from str
 */

char **split_string(char *str, char *delim)
{
	char **word_array;
	char *token;
	int words, i = 0;

	words = word_count(str);
	if (words == 0)
		return (NULL);

	word_array = malloc(sizeof(char *) * (words + 1));
	if (!word_array)
		return (NULL);

	token = strtok(str, delim);
	if (token == NULL)
		return (NULL);

	while (token != NULL)
	{
		word_array[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	return (word_array);
}
