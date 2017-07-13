#include "shakeup.h"

char *mallocBuffer(size_t length)
{
	char *buf;

	buf = malloc(length);
	if (buf == NULL)
		perror("Couldn't malloc the buffer to get user input");
        return (buf);
}

void getUserInput(char **buffer, size_t *length)
{
	ssize_t chars_read;

	chars_read = getline(buffer, length);
	if (chars_read == -1)
	{
		buffer[0] = '\n';
		write(1, &(buffer[0]), 1);
		free(buffer);
		exit(0);
	}
}

int checkEOF(char *buffer)
{
	unsigned int len;

	len = _strlen(buffer);
	if ((len >= 2) && (buffer[len - 1] == '4') && (buffer[len - 2] == '4'))
		return (0);
	return (-1);
}

char **parseBuffer(char *buffer)
{
	char **tokens = tokenize(buffer, " ");
	return (tokens);
}
