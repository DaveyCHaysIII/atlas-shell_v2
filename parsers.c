#include "hsh.h"

/**
 * parse_input - parses a string into tokens
 * @str_input: string that needs to be parsed
 * @delimiter: delimiters to use
 *
 * Return: matrix of tokens, otherwise NULL
 */

parsed_line_t *parse_input(parsed_line_t **head, char *str_input,
						   const char *delimiter)
{
	parsed_line_t *tmp, *newTok;
	char *tok = NULL;

	printf("in parser\n");
	printf("buffer in parser = %s\n", str_input);

	tok = strtok(str_input, delimiter);
	while (tok != NULL)
	{
		newTok = malloc(sizeof(parsed_line_t));
		if (newTok == NULL)
			return (NULL);
		newTok->tok_val = strdup(tok);
		// if (newTok->tok_val == NULL)
		// {
		// 	free(tok);
		// 	free(newTok);
		// 	free_parsed_line(head);
		// }
		newTok->next = NULL;

		if (head == NULL)
			*head = newTok;
		else
		{
			tmp = *head;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = newTok;
		}
		tok = strtok(NULL, delimiter);
	}

	free(tok);
	printf("exiting parser\n");
	return (*head);
}

/**
 * free_parsed_line - frees a linked list of a parsed str
 * @head: beginning of linked list
 *
 * Return: n/a
 */

void free_parsed_line(parsed_line_t **head)
{
	parsed_line_t *tmp;
	(void)tmp;

	printf("freeing shit\n");
	if (head == NULL)
		return;
	printf("here\n");
	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		printf("freeing tok_val\n");
		free(tmp->tok_val);
		printf("freeing list node\n");
		free(tmp);
	}
	printf("freed shit\n");
}
