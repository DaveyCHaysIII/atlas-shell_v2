#include "hsh.h"

/**
 * _getenv - gets an environment variable
 * @name: name of variable to find
 *
 * Return: name=value
 */

char *_getenv(char *name)
{
	char *env_var, *env_name, *env_val;
	int i;

	for (i = 0; shell_state.environ[i] != NULL; i++)
	{
		env_var = strdup(shell_state.environ[i]);
		if (env_var == NULL)
		{
			return (NULL);
		}
		env_name = strtok(env_var, "=");
		env_val = strtok(NULL, "=");

		if (_strcmp(env_name, name) == 0)
		{
			char *result = _strdup(env_val);
			free(env_var);
			return (result);
		}
		free(env_var);
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
int _setenv(char *name, char *value)
{
	int i;
	int name_len;
	char *new_var;
	char **env;

	if (name == NULL || value == NULL)
	{
		error_handler("setenv");
		return (-1);
	}
	name_len = _strlen(name);
	new_var = _str_char_concat(name, '=', value);

	env = shell_state.environ;
	for (i = 0; env[i] != NULL; i++)
	{
		if ((strncmp(env[i], name, _strlen(name)) == 0) &&
			(env[i][name_len] == '='))
		{
			free(env[i]);
			env[i] = new_var;
			return (0);
		}
	}
	return (0);
}

/**
 * _unsetenv - unsets an environment variable
 * @target: the environment variable in question
 *
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(char *target)
{
	//int i;
	//char **env = shell_state.environ;
	(void)target;
	return (0);
}
