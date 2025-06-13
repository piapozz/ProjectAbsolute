#pragma once
#include "UIScreen.h"

class UIWeapon : public BaseUIScreen
{
public:
	UIWeapon();
	~UIWeapon();

private:
	// ”wŒi
	UIScreenImage* _pBackground;
	// •Ší–¼
	UIScreenText* _pWeaponName;
	// ƒ‰ƒ“ƒN
	UIScreenText* _pWeaponRank;
	// UŒ‚‘®«
	UIScreenText* _pWeaponType;
	// UŒ‚—Í
	UIScreenText* _pWeaponAttack;
};

