#pragma once
#include "BaseAttack.h"

class AttackNormal: public BaseAttack
{
public:
	void Attack(BaseCharacter* chara) override;
};