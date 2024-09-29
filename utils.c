#include "hsh.h"

/**
 * error_handler - handles errors
 * @command: name of command that started the error
 *
 * Return: no return
 */

void error_handler(char *command)
{
	char *name = shell_state.program_name;

	if (errno == 0)
	{
		return;
	}
	if (errno == ENOTTY && !isatty(STDIN_FILENO))
	{
		return;
	}

	fprintf(stderr, "%s: %d: %s: %s\n",
		name,
		errno,
		command,
		strerror(errno));
}
