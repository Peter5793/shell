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
	void (*f)();
} _builtins_t;

_builtins_t *initBuiltins(void);
void findBuiltin(_builtins_t *b, char *cmd);
void runEnv();
void runExit();
void runSetenv();
void runUnsetenv();

#endif
