#pragma once
#include "../header/BaseWeapon.h"

class WeaponTriangle : public BaseWeapon
{
public:
	WeaponTriangle()
	{
		weaponName = "Triangle";
		weaponID = 1;

		damage = 5;
		damageType = Type::RED;
	}
};