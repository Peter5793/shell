#include "shakeup.h"
#include "builtins.h"

_builtins_t *initBuiltins(void)
{
	int numCommands = 8;
	_builtins_t *b;

	b = malloc(numCommands * sizeof(_builtins_t));
	if (b == NULL)
		return (NULL);

	b[0].command = "cd";
	b[0].f = (void *)runCd;
	b[1].command = "env";
	b[1].f = (void *)runEnv;
	b[2].command = "exit";
	b[2].f = (void *)runExit;
	b[3].command = "help";
	b[3].f = (void *)runHelp;
	b[4].command = "history";
	b[4].f = (void *)runHistory;
	b[5].command = "setenv";
	b[5].f = (void *)runSetenv;
	b[6].command = "unsetenv";
	b[6].f = (void *)runUnsetenv;

	b[7].command = NULL;
	b[7].f = NULL;

	return (b);
}

int findBuiltin(_builtins_t b[], char *cmd)
{
	int i = 0;

	while (b[i].command)
	{
		if (_strcmp(cmd, b[i].command) == 0)
		{
			return (b[i].f());
		}
		i++;
	}
	return (0);
}

void runCd()
{
	printf("runCd():\n");
}

void runEnv()
{
	printf("runEnv():\n");
}

void runExit()
{
	printf("runExit():\n");
}

void runHelp()
{
	printf("runHelp():\n");
}

void runHistory()
{
	printf("runHistory():\n");
}

void runSetenv()
{
	printf("runSetenv():\n");
}

void runUnsetenv()
{
	printf("runUnsetenv():\n");
}


int main()
{
	int test = 0;

	_builtins_t *b;
	char *c = "unsetenv";

	b = initBuiltins();
	test = findBuiltin(b, c);
	if (test == 0)
		printf("Didn't find command\n");

	free(b);
	return(0);
}
