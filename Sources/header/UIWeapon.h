#pragma once
#include "UIScreen.h"

class UIWeapon : public BaseUIScreen
{
public:
	UIWeapon();
	~UIWeapon();

private:
	// �w�i
	UIScreenImage* _pBackground;
	// ���햼
	UIScreenText* _pWeaponName;
	// �����N
	UIScreenText* _pWeaponRank;
	// �U������
	UIScreenText* _pWeaponType;
	// �U����
	UIScreenText* _pWeaponAttack;
};

