#include "hsh.h"

/**
 * main - entrypoint for hsh executable
 * @argc: number of CL inputs
 * @argv: matrix of CL inputs
 * @env: hsh evironment variables
 *
 * Return: 'EXIT_SUCCESS' or 'EXIT_FAILURE'
 */

int main(int argc, char **argv, char **env)
{
	int pipes, command;
	MemNode data;

	data = createList();
	while(1)
	{
		command = prompt(data);
		if (command == -1)
		{
			graceful_exit(data);
		}
		pipe = get_pipe_count(data->buffer);
		if (pipes == 0)
		{
			execute_command(data);
			free_memlist(data);
			continue;
		}
		else
		{
			execute_pipe_command(buffer, pipes);
			free_memlist(data);
			continue;
		}
	}
	free_memlist(data);
	return (EXIT_SUCCESS);
}

/**
 * prompt - initializes shell, prints prompt and reads input
 * @data: The linked list holding all the data
 * 
 * Return: 0 on success, -1 on failure
 */

int prompt(MemNode data)
{
	if (isatty)
		printf("%s", PROMPT);
			
}

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
 * graceful_exit - exits the program in a graceful manner
 * @data: the linked list holding all the data
 * 
 * Return: EXIT SUCCESS or EXIT FAILURE
 */

int graceful_exit(MemNode data)
{
	//error_handler();
	//free_memlist(data);
	//exit(0);
}
