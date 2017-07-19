#include "shakeup.h"

/**
 * findBuiltin - find if command is a builtin
 * @vars: general struct
 * @cmd: command to check
 * Return: run function if command is a builtin
 */
void findBuiltin(general_t *vars, char *cmd)
{
	int i = 0;
	_builtins_t *b = vars->builtins;

	while (b[i].command)
	{
		if (_strcmp(cmd, b[i].command) == 0)
			b[i].f(vars);
		i++;
	}
}
