#pragma once
#include <vector>
#include "../header/CommonModule.h"

class SecureRoom;
class BaseCharacter;

struct StateArgs
{
	std::vector<Vector2> targetPosList;
	SecureRoom* secureRoom;
	BaseCharacter* targetCharacter;
	CharacterStateID stateID;

	static StateArgs* Create(std::vector<Vector2> targetPosList, CharacterStateID nextStateID, SecureRoom* secureRoom = nullptr)
	{
		StateArgs* args = new StateArgs();
		args->targetPosList = targetPosList;
		args->stateID = nextStateID;
		args->secureRoom = secureRoom;
		return args;
	}

	static StateArgs* Create(std::vector<Vector2> targetPosList, CharacterStateID nextStateID, BaseCharacter* targetCharacter = nullptr)
	{
		StateArgs* args = new StateArgs();
		args->targetPosList = targetPosList;
		args->stateID = nextStateID;
		args->targetCharacter = targetCharacter;
		return args;
	}
};