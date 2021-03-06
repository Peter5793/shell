#include "shakeup.h"

/**
 * findBuiltin - find if command is a builtin
 * @genHead: general struct
 * @cmd: command to check
 * Return: run function if command is a builtin
 */
void findBuiltin(general_t *genHead, char *cmd)
{
	int i = 0;
	builtins_t *b = genHead->builtins;

	while (b[i].command)
	{
		if (_strcmp(cmd, b[i].command) == 0)
			b[i].f(genHead);
		i++;
	}
}
