#include "shakeup.h"

int main(void)
{
	char buf[101];
	ssize_t charsRead;

	charsRead = read(0, &buf, 101);
	if (charsRead == 0)
		interactiveShell();
	else
		nonInteractiveShell(buf);
	return (0);
}
