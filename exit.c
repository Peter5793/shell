#include "shakeup.h"

/**
 * runExit - runs exit routine
 * @genHead: general struct
 * Return: none
 */
void runExit(general_t *genHead)
{
	freeStruct(genHead);
	exit(0);
}
