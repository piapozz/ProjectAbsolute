#include "../header/OfficerStateFactory.h"

BaseOfficerState* OfficerStateFactory::CreateState(OfficerStateID stateID)
{
	if (stateID == OfficerStateID::NONE) return nullptr;
	if (stateID == OfficerStateID::OFFICER_IDLE) return new OfficerStateIdle();
	else if (stateID == OfficerStateID::OFFICER_MOVE) return new OfficerStateMove();
	else if (stateID == OfficerStateID::OFFICER_FIGHT) return new OfficerStateFight();
	else if (stateID == OfficerStateID::OFFICER_PANIC) return new OfficerStatePanic();
	else if (stateID == OfficerStateID::OFFICER_DEAD) return new OfficerStateDead();

	return nullptr;
}