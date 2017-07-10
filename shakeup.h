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
char **tokenize(char *str, char delim[]);

#endif /* SHAKEUP */
