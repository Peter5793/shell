#ifndef HSH_H
#define HSH_H

/**
 * struct list_s - singly linked list
 * @data: address to malloc'ed memory
 * @next: points to the next node in linked list
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	void *data;
	struct list_s *next;
} list_t;

/**
 * struct general_s - struct for shell
 * @nCommand: number of commands run by user
 * @head: head of linked list of malloc'ed memory
 */
typedef struct general_s
{
	unsigned int nCommands;
	list_t *head;
} general_t;


general_t *initStruct();
int add_address(general_t *main, void *ptr);
list_t *add_node_end(list_t **head, void *ptr);
void free_list(general_t *main);
size_t print_list(general_t *main);
list_t *add_node(list_t **head, void *ptr);

#endif
