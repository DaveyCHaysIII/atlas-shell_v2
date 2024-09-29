#include "hsh.h"

/**
 * createList - initializes head of MemNode linked list
 *
 * Return: pointer to head of linked list
 */

MemNode *createList()
{
	MemNode *newListNode;
	newListNode = malloc(sizeof(MemNode));

	newListNode->buffer = NULL;
	newListNode->commands = NULL;
	newListNode->next = NULL;

	return (newListNode);
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

	if (data == NULL)
		return;

	while (*data != NULL)
	{
		tmp = *data;
		*data = (*data)->next;
		free(tmp->buffer);
		free(tmp->commands);
		free(tmp);
	}
	*head = NULL;
}
