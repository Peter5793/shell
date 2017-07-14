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

	chars_read = getline(buffer, length, stdin);
	if (chars_read == -1)
	{
		buffer[0] = "\n";
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
	char delim[] = " ";

	char **tokens = tokenize(buffer, delim);
	return (tokens);
}


/*
// parse buffer
int main(void)
{
	char *buffer, **tokens;
	size_t len = 300, i;
	int eof = -1;

	buffer = mallocBuffer(len);
	getUserInput(&buffer, &len);
	tokens = parseBuffer(buffer);
	printf("Tokens double pointer: %p\n", (void *)tokens);
	for (i = 0; tokens[i]; i++)
		printf("Token %zu: %s, address: %p\n", i, tokens[i], (void *)tokens[i]);
	printf("NULL Buffer: %p\n", (void *)buffer);
	return (0);
}
*/

/*
// malloc buffer
int main(void)
{
	char *buffer;
	size_t len = 300;

	buffer = mallocBuffer(len);
	printf("Address: %p\n", (void *)buffer);
	printf("Contents: %s %zu\n", buffer, sizeof(buffer));
	return (0);
}
*/

/*
// get user input
int main(void)
{
	char *buffer;
	size_t len = 300;

	buffer = mallocBuffer(len);
	getUserInput(&buffer, &len);
	printf("User input: %s", buffer);
	return (0);
}
*/
