#include "shakeup.h"

void runExit(general_t *genHead)
{
        write(1, "runExit\n", 8);
	freeStruct(genHead);
	exit(0);
}
