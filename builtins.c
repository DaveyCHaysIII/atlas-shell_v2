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
	static char *prev_dir;
	char *home_dir = NULL;

	if (!args[1]) /* cd with no args */
	{
		home_dir = _getenv("HOME");
		if (!home_dir)
		{
			printf("cd: HOME not set\n");
			return;
		}
		prev_dir = _getenv("PWD");
		_cd_helper(home_dir);
	}
	else
	{
		if (_strcmp(args[1], "-") == 0)
		{
			if (!prev_dir)
				return;
			_cd_helper(prev_dir);
		}
		else
		{
			prev_dir = _getenv("PWD");
			_cd_helper(args[1]);
		}
	}
}

/**
 * _cd_helper - handles change directories
 * @path: path to change to
 *
 * Return: no return
 */

void _cd_helper(char *path)
{
	/* check if path is a directory */
	if (access(path, F_OK) == -1)
	{
		printf("cd: %s: No such file or directory\n", path);
		return;
	}
	if (chdir(path) == -1)
	{
		printf("cd: %s: Permission denied\n", path);
		return;
	}

	_setenv("PWD", path);
}

/**
 * _echo - prints off a message
 * @message: the message to send to stdout
 *
 * Return: no return
 */

void _echo(char *message)
{
	size_t len = _strlen(message);

	if (len >= 2 && message[0] == '"' && message[len - 1] == '"')
	{
		message[len - 1] = '\0';
		message++;
	}
	printf("%s\n", message);
}
