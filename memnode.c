#include "hsh.h"

/**
 * createList - initializes head of MemNode linked list
 *
 * Return: pointer to head of linked list (null)
 */

MemNode *createList()
{
	return (NULL);
}

/**
 * addNode - creates a new node
 * @data: the list structure
 *
 * Return: pointer to new node
 */

MemNode *addNode(MemNode **data)
{
	MemNode newNode = malloc(sizeof(MemNode));

	if (newNode == NULL)
	{
		free(newNode);
		return (NULL);
	}
	newNode->buffer = NULL;
	newNode->tokens = NULL;
	newNode->next = NULL;
	if (*data == NULL)
	{
		*data = newNode;
	}
	else
	{
		MemNode *current = *data;

		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}
	return (newNode);
}

/**
 * free_memlist - frees linked list of buffer structs
 * @data: head of linked list
 *
 * Return: n/a
 */

void free_memlist(MemNode **data)
{
	MemNode *tmp;
	int i;

	while (*data != NULL)
	{
		tmp = *head;

		if (tmp->buffer != NULL)
		{
			free(tmp->buffer;
		}
		if (tmp->tokens != NULL)
		{
			for (i = 0; tmp->tokens[i] != NULL; i++)
			{
				free(tmp->tokens[i]);
			}
			free(tmp->tokens);
		}
		*head = (*head)->next;
		free(tmp);
	}
	*head = NULL;
}
