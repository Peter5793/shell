#include "shakeup.h"

void freeAllMemory(general_t *genHead)
{
	freeEnv(genHead);
	freeList(genHead);
	freeStruct(genHead);
}

void runExit(general_t *genHead)
{
        write(1, "runExit\n", 8);
	freeAllMemory(genHead);

}
