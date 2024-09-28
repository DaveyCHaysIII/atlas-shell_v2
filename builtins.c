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
	printf("%s\n", _getenv("PWD"));
}

/**
 * _cd_handler - handles change directories
 * @args: array of args
 * 
 * Return: no return
 */

void _cd_handler(char **args)
{
	char *current_directory;
	char *new_directory;
	
	current_directory = _getenv("PWD");

	if ((args[0] != NULL) && (access(args[0], F_OK) != 0))
	{
		error_handler("cd");
		return;
	}

	if ((args[0] == NULL) || (strcmp(args[0], "~") == 0))
	{
		cd_helper(_getenv("HOME"));
	}
	else if (strcmp(args[0], "-") == 0)
	{
		cd_helper(_getenv("OLD_PWD"));
	}
	else
	{
		cd_helper(args[0]);
	}
}

/**
 * _cd - changes directory
 * @new_directory - the directory we're changing to
 * @current_directory - the directory we've come from
 * @home - the home directory
 *
 * Return: no return
 */

void _cd(char *new_directory)
{
	char *current_directory = _getenv("PWD");
	char *home = _getenv("HOME");

	if (home == NULL)
	{
		return;
	}
	if (current_directory == NULL)
	{
		_setenv("PWD", NULL);
		current_directory = _getenv("PWD"); 
	}

	_setenv("OLD_PWD", current_directory);
	if (chdir(new_directory) != 0)
	{
		error_handler("cd");
		return;
	}
	else
	{
		_setenv("PWD", new_directory);
	}
}

/**
 * _echo - prints off a message
 * @message: the message to send to stdout
 *
 * Return: no return
 */

void _echo(const char *message)
{
	printf("%s\n", message);
}
