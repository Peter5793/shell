#ifndef SHAKEUP
#define SHAKEUP

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int start_shell();
void shakeup_error(char *func_name_instance, int code);
char **tokenize(char *str, char delim[]);
unsigned int _strlen(const char *str);
char *_strdup(const char *s);
char *_strcat(char *dest, char *source);

#endif /* SHAKEUP */
