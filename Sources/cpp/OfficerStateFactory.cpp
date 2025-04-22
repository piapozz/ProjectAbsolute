#include "../header/OfficerStateFactory.h"

BaseOfficerState* OfficerStateFactory::CreateState(OfficerStateID stateID, StateArgs* args)
{
	switch (stateID)
	{
		case OfficerStateID::OFFICER_IDLE:
			return new OfficerStateIdle();
		case OfficerStateID::OFFICER_MOVE:
			return new OfficerStateMove(args->targetPosList);
		case OfficerStateID::OFFICER_OPERATION_MOVE:
			return new OfficerStateOperationMove(args->targetPosList, args->secureRoom);
		case OfficerStateID::OFFICER_FIGHT:
			return new OfficerStateFight();
		case OfficerStateID::OFFICER_PANIC:
			return new OfficerStatePanic();
		case OfficerStateID::OFFICER_DEAD:
			return new OfficerStateDead();
		default:
			return nullptr;
	}
}