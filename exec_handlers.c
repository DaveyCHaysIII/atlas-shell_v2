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
	int cnt_redirects = 0;
	pid_t pid;

	cmd_arr = parse_input(cmd_input, " ");
	if (builtin_handler(cmd_arr) > 0)
	{
		freematrix(cmd_arr);
		return;
	}
	cnt_redirects = count_redirects(cmd_arr);
	printf("cnt_redirects: %d\n", cnt_redirects);
	cmd_arr[0] = pathfinder(shell_state.path, cmd_arr[0]);
	if (cmd_arr[0] == NULL)
	{
		freematrix(cmd_arr);
		return;
	}

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

void exec_pipe_command(MemNode data, int num_pipes)
{
	(void)data;
	(void)num_pipes;
	// create pipes
	//  for(int i = 0; i < pipes; i++)
	{
		// handle dup2
		// dup2(pipefd[i], stdout);
		// dup2(pipefd[i+1], stdin);
		// fork
		// if (pid = 0)
		// input_parser()
		// execute_command();
		// else
		// wait
	}
	return;
}

/**
 * freematrix - frees a matrix
 * @matrix: matrix to be freed
 *
 * Return: n/a
 */

void freematrix(char **matrix)
{
	long unsigned int i = 0;

	for (i = 0; i < sizeof(matrix); i++)
		free(matrix[i]);
	free(matrix);
	return;
}
