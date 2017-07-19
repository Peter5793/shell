#include "shakeup.h"

/**
 * addMemAddress - add the memory address into linked list for freeing later
 * @main: pointer to program strut
 * @ptr: pointer to the malloc'ed memory
 * Result: 0 if success, -1 if fail
 */
int addMemAddress(general_t *genHead, void *ptr)
{
	if ((genHead == NULL) || (ptr == NULL))
		return (-1);

	addNodeEnd(&(genHead->head), ptr);
	return (0);
}

/**
 * addNodeEnd - adds a new node at the beginning of a list_t list
 * @head: pointer to new list node
 * @ptr: ptr element in list element
 * Return: address of the new element or NULL if it failed
 */
list_t *addNodeEnd(list_t **head, void *ptr)
{
	list_t *newnode = NULL;
	list_t *list = NULL;

	newnode = malloc(sizeof(list_t));
	if (newnode == NULL)
		return (NULL);
	list = *head;

	newnode->data = ptr;
	if (*head != NULL)
	{
		while ((list)->next != NULL)
		{
			list = (list)->next;
		}

		(list)->next = newnode;
		newnode->next = NULL;
	}
	else
	{
		*head = newnode;
		newnode->next = NULL;
	}
	return (newnode);
}

/**
 * printList - prints all the elements of a list_t list
 * @genHead: linked list
 * Return: size of linked list
 */
size_t printList(general_t *genHead)
{
	unsigned int count = 0;

	while (genHead->head)
	{
		count++;
		genHead->head = genHead->head->next;
	}

	return (count);
}

/**
 * addNode - adds a new node at the beginning of a list_t list.
 * @head: pointer to new list node
 * @ptr: pointer to memory address to be stored in list element
 * Return: address of the new element or NULL if it failed
 */
list_t *addNode(list_t **head, void *ptr)
{
	list_t *newnode = NULL;

	newnode = malloc(sizeof(list_t));
	if (newnode == NULL)
		return (NULL);

	newnode->data = ptr;

	if (*head != NULL)
	{
		newnode->next = *head;
		*head = newnode;
	}
	else
	{
		*head = newnode;
		newnode->next = NULL;
	}

	return (newnode);
}
