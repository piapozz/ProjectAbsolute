#include "../header/CharacterStateFactory.h"

BaseCharacterState* CharacterStateFactory::CreateState(OfficerStateID stateID, StateArgs* args)
{
	switch (stateID)
	{
		case OfficerStateID::OFFICER_IDLE:
			return new CharacterStateIdle();
		case OfficerStateID::OFFICER_MOVE:
			return new CharacterStateMove(args->targetPosList);
		case OfficerStateID::OFFICER_OPERATION:
			return new CharacterStateOperation(args->secureRoom);
		case OfficerStateID::OFFICER_OPERATION_MOVE:
			return new CharacterStateOperationMove(args->targetPosList, args->secureRoom);
		case OfficerStateID::OFFICER_FIGHT:
			return new CharacterStateFight();
		case OfficerStateID::OFFICER_PANIC:
			return new CharacterStatePanic();
		case OfficerStateID::OFFICER_DEAD:
			return new CharacterStateDead();
		default:
			return nullptr;
	}
}