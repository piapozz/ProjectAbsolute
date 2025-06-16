#pragma once
#include "../header/BaseWeapon.h"

class WeaponTriangle : public BaseWeapon
{
public:
	WeaponTriangle()
	{
		weaponID = 1;
		damageType = Type::RED;
	}
};