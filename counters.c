#include "hsh.h"

/**
 * get_pipe_count - simple function to read number of pipe commands
 * @buffer: the buffer to parse over
 *
 * Return: number of pipes in command
 */

int get_pipe_count(char *buffer)
{
	int i, pipes;

	pipes = 0;
	for (i = 1; buffer[i] != '\0'; i++)
	{
		if (buffer[i] == '|' &&
			buffer[i - 1] == ' ' &&
			buffer[i + 1] == ' ')
		{
			pipes++;
		}
	}
	return (pipes);
}

/**
 * count_redirects - counts the number of redirects
 * @cmd_tokens: tokenized strings of CL input
 *
 * return: number of redirects, or -1 on failure
 */

int count_redirects(char **cmd_arr)
{
	int count = 0;
	int i;

	printf("in count redirect\n");
	for (i = 0; i < MAX_ARR_SIZE; i++)
	{
		if (strcmp(cmd_arr[i], ">") == 0)
			count++;
	}
	return (count);
}

/**
 * _strlen()- gives length of string
 * @str: string in question
 *
 * Return: length of string
 */

unsigned int _strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
