#include "hsh.h"

/**
 * print_env - prints the environment
 *
 * Return: no return
 */

void print_env(void)
{
	int i;

	i = 0;
	while (shell_state.environ[i] != NULL)
	{
		printf("%s\n", shell_state.environ[i]);
		i++;
	}
}

/**
 * print_pwd - prints the pwd
 *
 * Return: no return
 */

void print_pwd(void)
{
	char *result = _getenv("PWD");
	if (result == NULL)
	{
		free(result);
		return;
 	}
	printf("%s\n", result);
		free(result);
}

/**
 * _cd_handler - handles change directories
 * @args: array of args
 *
 * Return: no return
 */

void _cd_handler(char **args)
{
	if (_getenv("PWD") == NULL)
	{
		char cwd_directory[4096];

		if (getcwd(cwd_directory, 4096) == NULL)
		{
			error_handler("cd");
			return;
		}
		if (_setenv("PWD", cwd_directory) == -1)
			return;
	}
	if ((args[1] != NULL) && (access(args[0], F_OK) != 0))
	{
		error_handler("cd");
		return;
	}
	if ((args[1] == NULL) || (strcmp(args[1], "~") == 0))
	{
		if (_getenv("HOME") == NULL)
			return;
		_cd(_getenv("HOME"));
	}
	else if (strcmp(args[0], "-") == 0)
	{
		if (_getenv("OLD_PWD") == NULL)
			return;
		_cd(_getenv("OLD_PWD"));
	}
	else
		_cd(args[0]);
}

/**
 * _cd - changes directory
 * @new_directory: the directory we're changing to
 *
 * Return: no return
 */

void _cd(char *new_directory)
{
	char *current_directory = _getenv("PWD");

	/*_setenv("OLD_PWD", current_directory);*/
	if (chdir(new_directory) != 0)
	{
		error_handler("cd");
		return;
	}
	else
	{
		/*_setenv("PWD", new_directory);*/
		return;
	}
}

/**
 * _echo - prints off a message
 * @message: the message to send to stdout
 *
 * Return: no return
 */

void _echo(char *message)
{
	printf("%s\n", message);
}
