#pragma once
#include "CommonModule.h"
#include "Const.h"

struct OfficerInitData
{
	Vector2 position;
	int health = 100;
	int mental = 100;

	int armorID = -1;
	int weaponID = -1;
	OfficerType type = OfficerType::NONE;
};