#include "../header/CharacterStateFactory.h"

BaseCharacterState* CharacterStateFactory::CreateState(CharacterStateID stateID, StateArgs* args)
{
	switch (stateID)
	{
		case CharacterStateID::IDLE:
			return new CharacterStateIdle();
		case CharacterStateID::MOVE:
			return new CharacterStateMove(args->targetPosList);
		case CharacterStateID::OPERATION:
			return new CharacterStateOperation(args->secureRoom);
		case CharacterStateID::OPERATION_MOVE:
			return new CharacterStateOperationMove(args->targetPosList, args->secureRoom);
		case CharacterStateID::FIGHT:
			return new CharacterStateFight();
		case CharacterStateID::FIGHT_MOVE:
			return new CharacterStateFightMove(args->targetPosList, args->targetCharacter);
		case CharacterStateID::PANIC:
			return new CharacterStatePanic();
		case CharacterStateID::DEAD:
			return new CharacterStateDead();
		default:
			return nullptr;
	}
}