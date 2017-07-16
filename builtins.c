#include "shakeup.h"

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
