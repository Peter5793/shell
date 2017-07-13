#include "shakeup.h"

/**
 * printPrompt - Prints the prompt
 * @prompt: The prompt to print
 *
 */

void printPrompt(char *prompt)
{
	unsigned int length;

	length = _strlen(prompt);
	write(1, &prompt, (size_t)length);
}
