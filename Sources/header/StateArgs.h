#pragma once
#include <vector>
#include "../header/CommonModule.h"

class SecureRoom;

struct StateArgs
{
	std::vector<Vector2> targetPosList;
	SecureRoom* secureRoom;
};