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
		char *eq = strchr(env[i], '=');

		if (eq != NULL)
		{
			if (strncmp(env[i], name, eq - env[i]) == 0)
			{
				return (eq + 1);
			}
		}
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
	size_t name_len, value_len;
	char *new_var;
	char **env;

	env = shell_state.environ;
	name_len = strlen(name);
	value_len = (value != NULL) ? strlen(value) : 0;
	new_var = malloc(name_len + value_len + 2);
	if (new_var == NULL)
	{
		return (-1);
	}

	if (value != NULL)
	{
		sprintf(new_var, "%s=%s", name, value);
	}
	else
	{
		sprintf(new_var, "%s=", name);
	}
	for (i = 0; env[i] != NULL; i++)
	{
		if ((strcmp(env[i], name, name_len) == 0) &&
			(env[i][name_len] == '='))
		{
			free(env[i];
			env[i] = new_var;
			return (0);
		}
	}
	env[i] = new_var;
	env[i + 1] = NULL;
	return (0);
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
