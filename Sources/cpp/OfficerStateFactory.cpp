#include "../header/OfficerStateFactory.h"

BaseOfficerState* OfficerStateFactory::ChangeState(OfficerStateID stateID)
{
	return new OfficerStateDead();
}