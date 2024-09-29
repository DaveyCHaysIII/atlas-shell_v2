#include "hsh.h"

/**
 * _getenv- gets an environment variable
 * @name: name of variable to get
 *
 * Return: value of that environment variable
 */

char *_getenv(const char *name)
{
	int i;
	char **env = shell_state.environ;

	if (name == NULL)
		return (NULL);

	for (i = 0; env[i] != NULL; i++)
	{
		//finish later
	}
	return (NULL);
}

/**
 * _setenv - sets an environment variable
 * @target: the environment variable in question
 * @value: the value we want to set target to
 *
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *name, const char *value)
{
	int i;
	char tmp[1024];
	char *new_var;
	char **env;

	if (name == NULL || value == NULL)
	{
		error_handler("setenv");
		return (-1)
	}
	new_var = _str_char_concat(name, '=', value);

	env = shell_state.environ;
	for (i = 0; env[i] != NULL; i++)
	{
		if ((strncmp(env[i], name, _strlen(name)) == 0) &&
			(env[i][name_len] == '='))
		{
			free(env[i];
			env[i] = new_var;
			return (0);
		}
	}
	//REALLOC section ??
	//env[i] = new_var;
	//env[i + 1] = NULL;
	//return (0);
}

/**
 * _unsetenv - unsets an environment variable
 * @target: the environment variable in question
 *
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *target)
{
	int i;
	char **env = shell_state.environ;


}
