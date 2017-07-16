#ifndef BUILTINS_H
#define BUILTINS_H

/**
 * struct builtins__ - struct for matching command lines with functions
 * @prType: char to determine type to print
 * @f: associated function
 */
typedef struct _builtins_s
{
	char *command;
	int (*f)();
} _builtins_t;

_builtins_t *initBuiltins(void);
int findBuiltin(_builtins_t *b, char *cmd);
void runCd();
void runEnv();
void runExit();
void runHelp();
void runHistory();
void runSetenv();
void runUnsetenv();

#endif
