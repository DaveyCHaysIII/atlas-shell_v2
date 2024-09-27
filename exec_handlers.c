#include "hsh.h"

/**
 * exec_pipe_command - handles commands with pipes
 * @data: the list holding all the data
 * @num_pipes: number of pipes
 *
 * Return: no return
 */

void exec_pipe_command(MemNode data, int num_pipes)
{
	//create pipes
	for(int i = 0; i < pipes; i++)
	{
		//handle dup2
			//dup2(pipefd[i], stdout);
			//dup2(pipefd[i+1], stdin);
		//fork
		//if (pid = 0)
		//input_parser()
		//execute_command();
		//else 
		//wait
	}
}
