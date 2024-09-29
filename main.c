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

	shell_state.environ = env;
	shell_state.program_name = argv[0];
	(void)argc;
	(void)argv;
	(void)env;

	data = createList();
	while (running)
	{
		command = prompt(data);
		if (command == -1)
		{
			graceful_exit(*data);
		}
		printf("getline buffer is : %s\n", data->buffer); // erase debug print
		if (strcmp(data->buffer, "exit") == 0)
		{
			running = 0;
			printf("exiting\n"); // erase debug print
			free_memlist(&data);
			return (EXIT_SUCCESS);
		}
		pipes = get_pipe_count(data->buffer);
		printf("Number of pipes = %d\n", pipes); // erase debug print
		if (pipes == 0)
		{
			printf("going to exe\n");
			execute_command(data->buffer);
		}
		// else
		// {
		// 	execute_pipe_command(data, pipes);
		// 	free_memlist(data);
		// 	continue;
		// }
		printf("moving on\n");
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
 * graceful_exit- exits the program
 * @data: the list we need to free
 * @program: the program that caused the exit
 * @code: a string of a number or null
 *
 * Return: no return
 */

void graceful_exit(MemNode **data, const char *program, const char* code)
{
	if (code == NULL)
	{
		code = "0";
	}
	else
	{
		code = atoi(code);
	}
	if (code < 0)
	{
		error_handler(program);
		return;
	}
	else
	{
		free_memlist(&data);
		error_handler(program);
		code = code % 256;
		exit(code);
	}
}

