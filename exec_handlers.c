#include "hsh.h"

/**
 * execute_command - executes CL input
 * @cmd_input: CL input to be executed
 *
 * Return: n/a
 */

void execute_command(char *cmd_input)
{
	const char **cmd_tokens = NULL; // make a free func
	int numRedirects = 0;

	cmd_tokens = parse_input(cmd_input, WHITESPACE);
	numRedirects = count_redirects(cmd_tokens);
	printf("number redirects = %d\n", numRedirects);
	freematrix(cmd_tokens);
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
