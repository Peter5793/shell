#include "shakeup.h"

int main(int argc, char **argv, char **env)
{
	char buf[101];
	ssize_t charsRead;

	charsRead = read(0, &buf, 101);
	if (charsRead == 0)
		interactiveShell(env);
	else
		nonInteractiveShell(buf);
	return (0);
}
