#pragma once
#include <vector>
#include "../header/CommonModule.h"

class SecureRoom;

struct StateArgs
{
	std::vector<Vector2> targetPosList;
	SecureRoom* secureRoom;

	static StateArgs* Create(std::vector<Vector2> targetPosList, SecureRoom* secureRoom = nullptr)
	{
		StateArgs* args = new StateArgs();
		args->targetPosList = targetPosList;
		args->secureRoom = secureRoom;
		return args;
	}
};