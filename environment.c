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
		env_var = _strdup(shell_state.environ[i]);
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
 * @name: the environment variable in question
 * @value: the value we want to set target to
 *
 * Return: 0 on success, -1 on failure
 */
int _setenv(char *name, char *value)
{
	int i;
	int name_len, value_len;
	char *new_var;

	if (name == NULL || value == NULL)
	{
		error_handler("setenv");
		return (-1);
	}

	name_len = _strlen(name);
	value_len = _strlen(value);

	for (i = 0; shell_state.environ[i] != NULL; i++)
		if (_strncmp(shell_state.environ[i], name, name_len) == 0)
			break;
	new_var = malloc(sizeof(char) * (name_len + value_len + 2));
	new_var = _str_char_concat(name, '=', value);
	if (shell_state.environ[i])
		_strcpy(shell_state.environ[i], new_var);
	else
	{
		printf("realloc has not been written for env\n");
		return (-1);
	}

	free(new_var);
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
	(void)target;
	return (0);
}
