#include "shakeup.h"

/**
 * freeEnv - free environment data struct
 * @genHead: pointer to main struct
 * Return: none
 */
void freeEnv(general_t *genHead)
{
	free(genHead->_env);
}

/**
 * freeList - free list_t list
 * @genHead: pointer to new list node
 * Return: none
 */
void freeList(general_t *genHead)
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
 * freeStruct - free main program general_t struct
 * @genHead: pointer to main struct
 * Return: none
 */
void freeStruct(general_t *genHead)
{
	list_t *node;

	if ((genHead == NULL) || (genHead->head = NULL))
		return;
	/*free memory pointed to by data*/
	while (genHead->head != NULL)
	{
		node = genHead->head->next;
		free(genHead->head->data);
		free(genHead->head);
		genHead->head = node;
	}

	free(genHead->_env);
	free(genHead->builtins);
}
