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
	if (args[1])
	{
		printf("You're about to cd to %s\n", args[1]);
	}
	else
		printf("cd to nowhere!");
	/*if(chdir(args[1]) != 0)
	{
		error_handler("cd");
		return;
	}*/
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
	size_t len = _strlen(message);

	if (len >= 2 && message[0] == '"' && message[len - 1] == '"')
	{
		message[len - 1] = '\0';
		message++;
	}
	printf("%s\n", message);
}
