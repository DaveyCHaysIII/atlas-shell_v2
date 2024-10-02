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
	if (newListNode == NULL)
	{
		return (NULL);
	}
	newListNode->buffer = NULL;
	newListNode->tokens = NULL;
	newListNode->next = NULL;

	return (newListNode);
}

/**
 * addNode - creates a new node
 * @data: the list structure
 *
 * Return: pointer to new node
 */

MemNode *addNode(MemNode **data)
{
	MemNode *newNode = malloc(sizeof(struct MemNode));
	int i;

	if (newNode == NULL)
		return (NULL);

	newNode->buffer = NULL;
	newNode->tokens = malloc(sizeof(char *) * MAX_ARR_SIZE);
	if (newNode->tokens == NULL)
	{
		free(newNode);
		return (NULL);
	}
	for (i = 0; i < MAX_ARR_SIZE; i++)
	{
		newNode->tokens[i] = NULL;
	}
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

		if (tmp->buffer != NULL)
		{
			free(tmp->buffer);
		}
		if (tmp->tokens != NULL)
		{
			int i;

			for (i = 0; tmp->tokens[i] != NULL; i++)
			{
				free(tmp->tokens[i]);
			}
			free(tmp->tokens);
		}
		*data = (*data)->next;
		free(tmp);
	}
	*data = NULL;
}
