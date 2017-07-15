#ifndef SHAKEUP
#define SHAKEUP
#define HSHPATH "PATH"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int interactiveShell();
int nonInteractiveShell();
char **tokenize(char *str, char delim[]);
unsigned int _strlen(const char *str);
char *_strdup(const char *s);
char *__strcat(char *dest, char *source);
char *mallocBuffer(size_t length);
char *getUserInput(char *buffer, size_t *length);
int checkEOF(char *buffer);
char **parseBuffer(char *buffer);
void printPrompt(char *prompt);
size_t correctAbsPath(char *token);
char *findCmd(char *b);
int createFork(char **bufferTokens);
char *createCWDFile(char *file);

#endif /* SHAKEUP */
