#include "shakeup.h"

void runExit(general_t *genHead)
{
	freeStruct(genHead);
	exit(0);
}
