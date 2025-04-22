#pragma once
#include "CommonModule.h"
#include "Const.h"

struct OfficerInitData
{
	Vector2 position = Vector2(0, 0);
	int health = 100;
	int mental = 100;

	int armorID = -1;
	int weaponID = -1;
	OfficerType type = OfficerType::NONE;
};