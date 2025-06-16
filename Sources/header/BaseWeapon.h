#pragma once
#include "../header/Const.h"

class BaseWeapon
{
public:
	BaseWeapon()
	{
		weaponID = 0;
		damageType = Type::RED;
	}

	virtual void Effect(){};
	virtual void Passive(){};

protected:
	// ID
	int weaponID;
	// ƒ_ƒ[ƒW‘®«
	Type damageType;
	// ‰æ‘œ

	// à–¾•¶
};