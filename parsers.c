#include "hsh.h"

/**
 * parse_input - parses a string into tokens
 * @str_input: string that needs to be parsed
 * @delimiter: delimiters to use
 *
 * Return: matrix of tokens, otherwise NULL
 */

char **parse_input(char *str_input, const char *delimiter)
{
	char **tok_arr = NULL;
	char *str_copy = NULL;
	char *tok = NULL;
	int i = 0;

	if (!str_input || !delimiter)
		return NULL;

	str_copy = strdup(str_input); // Create a copy of the input string
	if (!str_copy)
		return NULL;

	tok_arr = malloc(sizeof(char *) * MAX_ARR_SIZE);
	if (!tok_arr)
	{
		free(str_copy);
		return NULL;
	}
	while (tok_arr && i < MAX_ARR_SIZE)
	{
		tok_arr[i] = NULL;
		i++;
	}
	i = 0;
	tok = strtok(str_copy, delimiter);
	while (tok && i < MAX_ARR_SIZE - 1)
	{
		tok_arr[i] = strdup(tok);
		if (!tok_arr[i])
		{
			// Handle memory allocation failure
			for (int j = 0; j < i; j++)
				free(tok_arr[j]);
			free(tok_arr);
			free(str_copy);
			return NULL;
		}
		tok = strtok(NULL, delimiter);
		i++;
	}
	for (; i < MAX_ARR_SIZE; i++)
		tok_arr[i] = NULL;

	free(str_copy); // Free the copy of the input string
	return tok_arr;
}
