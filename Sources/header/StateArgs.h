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

	static StateArgs* Create(std::vector<Vector2> targetPosList, SecureRoom* secureRoom = nullptr)
	{
		StateArgs* args = new StateArgs();
		args->targetPosList = targetPosList;
		args->secureRoom = secureRoom;
		return args;
	}

	static StateArgs* Create(std::vector<Vector2> targetPosList, BaseCharacter* targetCharacter = nullptr)
	{
		StateArgs* args = new StateArgs();
		args->targetPosList = targetPosList;
		args->targetCharacter = targetCharacter;
		return args;
	}
};