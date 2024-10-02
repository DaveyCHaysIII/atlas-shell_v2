#include "hsh.h"

/**
 * error_handler - handles errors
 * @command: name of command that started the error
 *
 * Return: no return
 */

void error_handler(const char *command)
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

/**
 * _strspn()- compares prefix to string
 * @s: the string in question
 * @accept: the prefix substring in question
 *
 * Return: length of prefix
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j, output;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			output = 1;
			if (s[i] != accept[j])
			{
				output = output;
			}
			else
			{
				output = 0;
				break;
			}
		}
		if (output > 0)
		{
			return (i);
		}
	}
	return (i);
}

/**
 * create_sanitized_buffer - creates a whitespace sanitized buffer
 * @buffer: the buffer that needs sanitizing
 *
 * Description: removes leading, trailing and excessive inter-argument whitespace
 *
 * Return: pointer to dynamically allocated sanitized char *
 */

char *create_sanitized_buffer(char *buffer)
{
	size_t i, j, whitecount;
	char tmp[1024];
	char *san_buffer;

	i = _strspn(buffer, " \t\n"); // start of meaningful input
	j = 0;
	whitecount = 0;
	while (buffer[i] != '\0')
	{
		if ((buffer[i] != ' ') && (buffer[i] != '\t') && (buffer[i] != '\n'))
		{
			whitecount = 0;
		}
		else if (whitecount == 0)
		{
			tmp[j++] = ' ';
			whitecount++;
		}
		else
		{
			i++;
			continue;
		}

		tmp[j++] = buffer[i];
		i++;
	}
	tmp[j] = '\0';

	if (j == 0)
		return (NULL);
	san_buffer = _strdup(tmp);
	if (!san_buffer)
		return (NULL);
	return san_buffer;
}
