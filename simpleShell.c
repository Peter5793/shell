#include "shakeup.h"

int main(void)
{
	char buf[101];
	ssize_t charsRead;

	charsRead = read(0, &buf, 101);
	if (chars_read == 0)
		interactiveShell();
	else
		nonInteractiveShell();
	return (0);
}
