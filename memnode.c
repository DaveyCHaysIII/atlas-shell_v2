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
	*data = NULL;
}
