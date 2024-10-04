#include "hsh.h"

#include <sys/wait.h>
#include <sys/stat.h>

/**
 * execute_command - executes CL input
 * @cmd_input: CL input to be executed
 *
 * Return: n/a
 */

void execute_command(char *cmd_input)
{
	char **cmd_arr;
	//int cnt_redirects = 0;
	pid_t pid;

	cmd_arr = parse_input(cmd_input, " ");
	if (builtin_handler(cmd_arr) > 0)
	{
		freematrix(cmd_arr);
		return;
	}
	//cnt_redirects = count_redirects(cmd_arr);
	cmd_arr[0] = pathfinder(shell_state.path, cmd_arr[0]);
	if (cmd_arr[0] == NULL)
	{
		freematrix(cmd_arr);
		return;
	}
	printf("command: [%s]\n", cmd_arr[0]);
	pid = fork();
	if (pid == 0)
	{
		while (cmd_arr)
		{
			if (execve(cmd_arr[0], cmd_arr, shell_state.environ) != 0)
			{
				freematrix(cmd_arr);
				exit(EXIT_FAILURE);
			}
		}
		exit(EXIT_SUCCESS);
	}
	wait(NULL);
	freematrix(cmd_arr);
}

/**
 * exec_pipe_command - handles commands with pipes
 * @data: the list holding all the data
 * @num_pipes: number of pipes
 *
 * Return: no return
 */

void exec_pipe_command(MemNode *data, int num_pipes)
{
	int i, j, pipefd[2 * num_pipes], status;
	pid_t pid;

	for (i = 0; i < num_pipes; i++)
	{
		if (pipe(pipefd + i * 2) == -1)
		{
			error_handler("pipe");
			return;
		}
		data->tokens = parse_input(data->buffer, "|");
		for(i = 0; i <= num_pipes; i++)
		{
			pid = fork();
			if (pid == -1)
			{
				error_handler("fork");
				return;
			}
			if (pid == 0)
			{
				if (i != 0)
				{
					if (dup2(pipefd[(i - 1) * 2], STDIN_FILENO) == -1)
					{
						error_handler("dup2");
						return;
					}

				}
				if (i != num_pipes)
				{
					if (dup2(pipefd[i * 2 + 1], STDOUT_FILENO) == -1)
					{
						error_handler("dup2");
						return;
					}
				}
				for (j = 0; j < 2 * num_pipes; j++)
					close(pipefd[j]);

				execute_command(data->tokens[i]);
				error_handler("exec");
				return;
			}
		}
		for (i = 0; i < 2 * num_pipes; i++)
			close(pipefd[i]);
		for (i = 0; i <= num_pipes; i++)
			wait(&status);
	}
}

/**
 * exec_semi_command - executes multiple commands
 * @data: the data node
 *
 * Return: no return
 */

void exec_semi_command(MemNode *data)
{
	int i;
	data->tokens = parse_input(data->buffer, ";");

	i = 0;
	while(data->tokens[i] != NULL)
	{
		execute_command(data->tokens[i]);
		error_handler(data->tokens[i]);
	}
}

/**
 * freematrix - frees a matrix
 * @matrix: matrix to be freed
 *
 * Return: n/a
 */

void freematrix(char **matrix)
{
	unsigned long int i = 0;

	for (i = 0; i < sizeof(matrix); i++)
		free(matrix[i]);
	free(matrix);
}
