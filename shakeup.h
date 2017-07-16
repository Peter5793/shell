#ifndef SHAKEUP
#define SHAKEUP
#define HSHPATH "PATH"
#define ENVSIZE 4000

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

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
 * struct builtins__ - struct for matching command lines with functions
 * @prType: char to determine type to print
 * @f: associated function
 */
typedef struct _builtins_s
{
	char *command;
	void (*f)();
} _builtins_t;

/**
 * struct general_s - struct for shell
 * @nCommand: number of commands run by user
 * @head: head of linked list of malloc'ed memory
 */
typedef struct general_s
{
	char **_env;
	_builtins_t *builtins;
	unsigned int nCommands;
	list_t *head;
} general_t;


_builtins_t *initBuiltins(void);
general_t *initStruct(char **env);
int interactiveShell(char **env);
int nonInteractiveShell(char *buffer);
char **tokenize(char *str, char delim[]);
unsigned int _strlen(const char *str);
char *_strdup(const char *s);
char *__strcat(char *dest, char *source);
int _strcmp(char *s1, char *s2);
char *mallocBuffer(size_t length);
char *getUserInput(char *buffer, size_t *length);
int checkEOF(char *buffer);
char **parseBuffer(char *buffer);
void printPrompt(char *prompt);
size_t correctAbsPath(char *token);
char *findCmd(char *b);
int createFork(char **bufferTokens);
char *createCWDFile(char *file);
char *_getenv(char *name);
void findBuiltin(general_t *vars, char *cmd);
void runEnv(general_t *genHead);
void runExit();
void runSetenv();
void runUnsetenv();
int addMemAddress(general_t *genHead, void *ptr);
list_t *addNodeEnd(list_t **head, void *ptr);
void freeList(general_t *genHead);
void freeStruct(general_t *genHead);
size_t printList(general_t *genHead);
list_t *addNode(list_t **head, void *ptr);

#endif
