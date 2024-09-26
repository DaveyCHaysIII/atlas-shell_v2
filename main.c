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
	MemNode *data;
	int running = 1;

	(void)argc;
	(void)argv;
	(void)env;
	(void)pipes;

	data = createList();
	while (running)
	{
		command = prompt(data);
		if (command == -1)
		{
			graceful_exit(data);
		}
		printf("%d\n", command);
		printf("%s\n", data->buffer);
		if (strcmp(data->buffer, "exit") == 0)
		{
			running = 0;
			printf("%d", running);
			free_memlist(&data);
			return (EXIT_SUCCESS);
		}
		// pipes = get_pipe_count(data->buffer);
		// if (pipes == 0)
		// {
		// 	execute_command(data->buffer);
		// 	free_memlist(data);
		// 	continue;
		// }
		// else
		// {
		// 	execute_pipe_command(data, pipes);
		// 	free_memlist(data);
		// 	continue;
		// }
		free(data->buffer);
	}

	graceful_exit(data);
	return (EXIT_SUCCESS);
}

/**
 * prompt - initializes shell, prints prompt and reads input
 * @data: The linked list holding all the data
 *
 * Return: 0 on success, -1 on failure
 */

int prompt(MemNode *data)
{
	// if isatty, print prompt
	// command = getline(data->buffer, 0, STDIN);
	if (isatty(STDIN_FILENO))
	{
		char *buff = NULL;
		size_t size = BUFF_SIZE;
		int bytes_read = 0;

		buff = malloc(sizeof(size));
		printf("%s > ", PROMPT);
		bytes_read = getline(&buff, &size, stdin);
		if (bytes_read < 0)
		{
			free(buff);
			return (-1);
		}
		buff[bytes_read - 1] = '\0';
		data->buffer = strdup(buff);
		free(buff);
	}
	return (0);
}

/**
 * get_pipe_count - simple function to read number of pipe commands
 * @buffer: the buffer to parse over
 *
 * Return: number of pipes in command
 */

int get_pipe_count(char *buffer)
{
	// finds match " | "
	(void)buffer;
	return (0);
}

/**
 * graceful_exit - exits the program in a graceful manner
 * @data: the linked list holding all the data
 *
 * Return: EXIT SUCCESS or EXIT FAILURE
 */

int graceful_exit(MemNode *data)
{
	free_memlist(&data);
	data = NULL;
	return (0);
}
