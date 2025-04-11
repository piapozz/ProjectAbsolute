#include "../header/BaseFase.h"

void BaseFase::ProcLoop()
{
	while (true)
	{
		if (Proc()) break;
	}
}