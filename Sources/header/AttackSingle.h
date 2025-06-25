#pragma once
#include "../header/BaseAttack.h"

class AttackSingle: public BaseAttack
{
	void Attack(BaseCharacter* attacker, BaseCharacter* characters) override;
};