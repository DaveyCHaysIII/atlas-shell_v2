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
		return NULL;

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
int _setenv(const char *target, const char *value)
{
	char **env = shell_state.environ;

	if (target == NULL)
	{
		return (-1);
	}
	if (value == NULL)
	{
		if (strcmp(target, "PWD") == 0)
		{
			//getcwd();
		}
	}
	//set 
}

/**
 * _unsetenv - unsets an environment variable 
 * @target: the environment variable in question
 * 
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *target)
{
	
}
