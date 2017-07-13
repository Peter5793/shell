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

#endif /* SHAKEUP */
