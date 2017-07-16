#include <stdio.h>
#include <stdlib.h>
#include "hsh.h"

/**
 * initStruct - initializes the hsh struct for tracking variables
 * @main: pointer to the struct
 * Result: pointer to general_t struct
 */
general_t *initStruct(void)
{
	general_t *main;
	char **e = NULL;
	int i;

	main = malloc(sizeof(general_t));
	if(main == NULL)
	{
		perror("main struct failed");
		return(NULL);
	}

	e = malloc(ENVSIZE * sizeof(char));
	if (e == NULL)
		return (NULL);

	while(envir[i])
	{
		e[i] = envir[i];
		printf("old:%s\nnew:%s\n", envir[i], e[i]);
		i++;
	}

	main->nCommands = 0;
	main->head = NULL;

	return (main);
}

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
	return(0);
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
	unsigned int n = 0;

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
/*		printf("%d:%p:%s\n", count, genHead->head->data, (char *)(genHead->head->data));*/
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
	unsigned int n = 0;

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

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
/*
int main(void)
{
	general_t *genHead = NULL;
	list_t *l = NULL;
	char *test1, *test2, *test3;

	genHead = initStruct();
	if (genHead == NULL)
		return(0);

	test1 = malloc(100 * sizeof(char));
	test2 = malloc(100 * sizeof(char));
	test3 = malloc(100 * sizeof(char));

	__strcat(test1,"hello");
	__strcat(test2, "world");
	__strcat(test3, "holberton");

	printf("test1:%p %s\n", (void *)test1, test1);
	printf("test2:%p %s\n", (void *)test2, test2);
	printf("test3:%p %s\n", (void *)test3, test3);

	if (addMemAddress(genHead, (void *)test1))
		printf("Added ptr:%s\n", test1);
	addMemAddress(genHead, (void *)test2);
	addMemAddress(genHead, (void *)test3);

	printList(genHead);
	freeList(genHead);
	freeStruct(genHead);
	genHead = NULL;

	return (0);
}
*/
