#include "hsh.h"

Shellstate shell_state;

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

	shell_state.environ = env;
	shell_state.program_name = argv[0];
	getpath(&shell_state.path);

	while (running)
	{
		data = createList();
		command = prompt(data);
		if (command == -1)
		{
			printf("\n");
			graceful_exit(&data, "main", "0");
		}
		else if (command == -2)
		{
			free_memlist(&data);
			continue;
		}
		if (strcmp(data->buffer, "exit") == 0)
		{
			break;
		}
		pipes = get_pipe_count(data->buffer);
		if (pipes == 0)
		{
			printf("getline buffer is [%s]\n", data->buffer);
			execute_command(data->buffer);
		}
		free_memlist(&data);
	}

	free_memlist(&data);
	freelist(&shell_state.path);
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
	char *buff = NULL;
	size_t size = BUFF_SIZE;
	int bytes_read = 0;

	buff = malloc(sizeof(size));
	if (buff == NULL)
	{
		return (-1);
	}
	if (isatty(STDIN_FILENO))
	{
		printf("%s > ", PROMPT);
	}
	bytes_read = getline(&buff, &size, stdin);
	if (bytes_read < 0)
	{
		free(buff);
		return (-1);
	}
	buff[bytes_read - 1] = '\0';
	data->buffer = create_sanitized_buffer(buff);
	if (data->buffer == NULL)
	{
		free(buff);
		return (-2);
	}
	free(buff);

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

void graceful_exit(MemNode **data, const char *program, const char *code)
{
	int num;

	num = atoi(code);

	if ((code == NULL) || (strcmp(code, "0") == 0))
	{
		num = 0;
	}
	else
	{
		if (num == 0)
		{
			program = "exit";
			error_handler(program);
			return;
		}
	}
	if (num < 0)
	{
		error_handler(program);
		return;
	}
	else
	{
		free_memlist(data);
		error_handler(program);
		num = num % 256;
		exit(num);
	}
}
