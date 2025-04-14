#include "../header/BasePhase.h"

void BasePhase::ProcLoop()
{
	while (true)
	{
		if (Proc()) break;
	}
}