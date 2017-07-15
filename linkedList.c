#include <stdio.h>
#include <stdlib.h>
#include "hsh.h"

/**
 * initStruct - initializes the hsh struct for tracking variables
 * @main: pointer to the struct
 * Result: pointer to general_t struct
 */
general_t *initStruct()
{
	general_t *main;

	main = malloc(sizeof(general_t));
	if(main == NULL)
	{
		perror("main struct failed");
		return(NULL);
	}

	main->nCommands = 0;
	main->head = NULL;

	return (main);
}

/**
 * add_address - add the memory address into linked list for freeing later
 * @ptr: pointer to the malloc'ed memory
 * Result: 0 if success, -1 if fail
 */
int add_address(general_t *main, void *ptr)
{
	if ((main == NULL) || (ptr == NULL))
		return (-1);

	add_node_end(&(main->head), ptr);
	return(0);
}

/**
 * add_node_end - adds a new node at the beginning of a list_t list
 * @head: pointer to new list node
 * @ptr: ptr element in list element
 * Return: address of the new element or NULL if it failed
 */
list_t *add_node_end(list_t **head, void *ptr)
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
 * free_list - free list_t list
 * @head: pointer to new list node
 * Return: none
 */
void free_list(general_t *main)
{
	list_t *node;

	if ((main == NULL) || (main->head = NULL))
		return;

	while (main->head != NULL)
	{
		node = main->head->next;
		free(main->head);
		main->head = node;
	}
}

/**
 * freeStruct - free main program general_t struct
 * @genHead: pointer to main struct
 * Return: none
 */
void freeStruct(general_t *genHead)
{
	list_t *node;

	if ((genHead == NULL) || (genHead->head = NULL))
		return;
	while (genHead->head != NULL)
	{
		node = genHead->head->next;
		free(genHead->head);
		genHead->head = node;
	}
}

/**
 * print_list - prints all the elements of a list_t list
 * @h: linked list
 * Return: size of linked list
 */
size_t print_list(general_t *main)
{
	unsigned int count = 0;

	while (main->head)
	{
/*		printf("%d: %p\n", count, main->head->data);
		printf("Contents:%s\n", (char *)(main->head->data));
*/		count++;
		main->head = main->head->next;
	}

	return (count);
}

/**
 * add_node - adds a new node at the beginning of a list_t list.
 * @head: pointer to new list node
 * @ptr: ptr to element in list element
 * Return: address of the new element or NULL if it failed
 */
list_t *add_node(list_t **head, void *ptr)
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

	printf("test1:%p %s\n", (void *)&test1, test1);
	printf("test2:%p %s\n", (void *)&test2, test2);
	printf("test3:%p %s\n", (void *)&test3, test3);

	if (add_address(genHead, (void *)test1))
		printf("Added ptr:%s\n", test1);
	add_address(genHead, (void *)test2);
	add_address(genHead, (void *)test3);

	print_list(genHead);
	free_list(genHead);
	freeStruct(genHead);
	genHead = NULL;

	return (0);
}
