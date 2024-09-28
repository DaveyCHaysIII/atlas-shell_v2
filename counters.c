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

int count_redirects(char **cmd_tokens)
{
	int count = 0;
	int i = 0;
	printf("in count redirect\n");
	if (!cmd_tokens)
		return (-1);

	for (i = 0; cmd_tokens[i] != NULL; i++)
	{
		printf("%s\n", cmd_tokens[i]);
	}
	return (count);
}
