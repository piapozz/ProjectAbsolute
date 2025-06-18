#pragma once
#include "../header/Const.h"

class BaseWeapon
{
public:
	BaseWeapon()
	{
		weaponName = "";
		weaponID = 0;

		damage = -1;
		damageType = Type::RED;
	}

	virtual void Effect(){};
	virtual void Passive(){};

	inline std::string GetName(){ return weaponName; }
	inline int GetDamage(){ return damage; }
	inline Type GetDamageType(){ return damageType; }

protected:
	// 名前
	std::string weaponName;
	// ID
	int weaponID;
	// ダメージ
	int damage;
	// ダメージ属性
	Type damageType;
	// 画像

	// 説明文
};