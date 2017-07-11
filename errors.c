#include "shakeup.h"

/**
 * shakeup_error - Temp error function
 * @func_name_instance: Name of function we're in
 * @code: The error code to send
 *
 */

void shakeup_error(char *func_name_instance, int code)
{
	const char *error;
	unsigned int i;
	char mut_error[100] = "Error: ";

	if (func_name_instance == NULL)
		exit(98);
	for(i = 0; i < func_name_instance[i]; i++)
		mut_error[7 + i] = func_name_instance[i];
	mut_error[i] = '\0';
	error = (const char *)mut_error;
	perror(error);
	exit(code);
}
