#include "hsh.h"

#include <fcntl.h>
#include <sys/wait.h>

/**
 * redirect_handler - manages what redirections are needed
 * @tok_strs: command array
 *
 * Return: void
 */

void redirect_handler(char **tok_strs, int cnt_redirects)
{
	(void)cnt_redirects;
	char **cmd_arr = NULL;
	int i = 0;

	while (tok_strs[i] != NULL)
	{
		if (_strcmp(tok_strs[i], ">") == 0)
		{
			cmd_arr = get_cmd_arr(tok_strs, i);
			single_right_redirect(cmd_arr, tok_strs[i + 1]);
		}
		else if (_strcmp(tok_strs[i], ">>") == 0)
		{
			cmd_arr = get_cmd_arr(tok_strs, i);
			double_right_redirect(cmd_arr, tok_strs[i + 1]);
		}
		else if (_strcmp(tok_strs[i], "<") == 0)
		{
			cmd_arr = get_cmd_arr(tok_strs, i);
			single_left_redirect(cmd_arr, tok_strs[i + 1]);
		}
		else if (_strcmp(tok_strs[i], "<<") == 0)
		{
			cmd_arr = get_cmd_arr(tok_strs, i);
			double_left_redirect(cmd_arr, tok_strs[i + 1]);
		}
		i++;
	}
}

/**
 * single_right_redirect - handles single right redirect
 * @tok_strs: command array
 * @pos: position of redirect
 *
 * Return: void
 */

void single_right_redirect(char **cmd_arr, char *file_name)
{
	int destfile, stdoutcpy;
	pid_t pid;

	stdoutcpy = dup(STDOUT_FILENO);

	destfile = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);

	if (destfile == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}

	dup2(destfile, STDOUT_FILENO);
	pid = fork();
	if (pid == 0)
	{
		while (cmd_arr)
		{
			if (execve(cmd_arr[0], cmd_arr, shell_state.environ) != 0)
			{
				freematrix(cmd_arr);
				error_handler(cmd_arr[0]);
				exit(EXIT_FAILURE);
			}
		}
		exit(EXIT_SUCCESS);
	}
	wait(NULL);
	freematrix(cmd_arr);
	dup2(stdoutcpy, STDOUT_FILENO);
	close(stdoutcpy);
	return;
}

/**
 * double_right_redirect - handles double right redirect
 * @tok_strs: command array
 * @pos: position of redirect
 *
 * Return: void
 */

void double_right_redirect(char **cmd_arr, char *file_name)
{
	int destfile, stdoutcpy;
	pid_t pid;

	stdoutcpy = dup(STDOUT_FILENO);

	destfile = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 0644);

	if (destfile == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}

	dup2(destfile, STDOUT_FILENO);
	pid = fork();
	if (pid == 0)
	{
		while (cmd_arr)
		{
			if (execve(cmd_arr[0], cmd_arr, shell_state.environ) != 0)
			{
				freematrix(cmd_arr);
				error_handler(cmd_arr[0]);
				exit(EXIT_FAILURE);
			}
		}
		exit(EXIT_SUCCESS);
	}
	wait(NULL);
	freematrix(cmd_arr);
	dup2(stdoutcpy, STDOUT_FILENO);
	close(stdoutcpy);
	return;
}

/**
 * single_left_redirect - handles single left redirect
 * @tok_strs: command array
 * @pos: position of redirect
 *
 * Return: void
 */

void single_left_redirect(char **cmd_arr, char *file_name)
{
	int inputfile, stdincpy;
	pid_t pid;

	stdincpy = dup(STDIN_FILENO);

	inputfile = open(file_name, O_RDONLY);

	if (inputfile == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}

	dup2(inputfile, STDIN_FILENO);
	pid = fork();
	if (pid == 0)
	{
		while (cmd_arr)
		{
			if (execve(cmd_arr[0], cmd_arr, shell_state.environ) != 0)
			{
				freematrix(cmd_arr);
				error_handler(cmd_arr[0]);
				exit(EXIT_FAILURE);
			}
		}
		exit(EXIT_SUCCESS);
	}
	wait(NULL);
	freematrix(cmd_arr);
	dup2(stdincpy, STDIN_FILENO);
	close(stdincpy);
	return;
}

/**
 * double_left_redirect - handles double left redirect
 * @tok_strs: command array
 * @pos: position of redirect
 *
 * Return: void
 */

void double_left_redirect(char **cmd_arr, char *delimiter)
{
	/*
	int tmpfile, stdincpy;
	char* file_name = NULL;
	pid_t pid;

	sprintf(file_name, "/tmp/%s", cmd_arr[0]);

	stdincpy = dup(STDIN_FILENO);

	tmpfile = open(file_name, O_RDONLY);

	if (tmpfile == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}

	dup2(tmpfile, STDIN_FILENO);
	pid = fork();
	if (pid == 0)
	{
		while (cmd_arr)
		{
			if (execve(cmd_arr[0], cmd_arr, shell_state.environ) != 0)
			{
				freematrix(cmd_arr);
				error_handler(cmd_arr[0]);
				exit(EXIT_FAILURE);
			}
		}
		exit(EXIT_SUCCESS);
	}
	wait(NULL);
	freematrix(cmd_arr);
	dup2(stdincpy, STDIN_FILENO);
	close(stdincpy);
	*/
	(void)cmd_arr;
	(void)delimiter;
	printf("double left redirect not implemented\n");
	return;
}
