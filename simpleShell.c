#include "shakeup.h"

int main(int argc, char **argv, char **env)
{
	char buf[101];
	ssize_t charsRead;
	general_t *genHead = NULL;

	genHead = initStruct(env, genHead);
	genHead->builtins = initBuiltins(genHead);

	charsRead = read(0, &buf, 101);
	if (charsRead == 0)
		interactiveShell(env, genHead);
	else
		nonInteractiveShell(buf, genHead);
	return (0);
}
