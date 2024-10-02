#include "hsh.h"

/**
 * builtin_handler - handles execution of builtins
 * @args: tokenized command to check
 *
 * Return: 0 if no builtin found, 1 if found
 */

int builtin_handler(char **args)
{
	if (_strcmp(args[0], "cd") == 0)
	{
		_cd_handler(args);
		return (1);
	}
	if (_strcmp(args[0], "pwd") == 0)
	{
		print_pwd();
		return (2);
	}
	if (_strcmp(args[0], "env") == 0)
	{
		print_env();
		return (3);
	}
	if (_strcmp(args[0], "setenv") == 0)
	{
		return (4);
	}
	if (_strcmp(args[0], "unsetenv") == 0)
	{
		return (5);
	}
	if (_strcmp(args[0], "echo") == 0)
	{
		if (args[1])
		{
			_echo(args[1]);
		}
		return (6);
	}
	return (0);
}
