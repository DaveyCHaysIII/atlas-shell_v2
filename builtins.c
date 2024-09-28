#include "hsh.h"

/**
 * graceful_exit- exits the program
 * @data: the list we need to free
 *
 * Return: no return
 */

void graceful_exit(MemNode **data)
{
	free_memlist(&data);
	error_handler();
	exit(EXIT_SUCCESS);
}

/**
 * print_env - prints the environment
 *
 * Return: no return
 */

void print_env(void)
{
	int i;

	i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

/**
 * change_directory - change directories
 * @args: array of args
 * 
 * Return: no return
 */

void change_directory (char **args)
{
	char *current_directory;
	
	current_directory = getcwd();
}

