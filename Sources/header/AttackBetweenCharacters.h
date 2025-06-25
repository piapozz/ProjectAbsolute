#pragma once
#include "../header/BaseAttack.h"

class AttackBetweenCharacters: public BaseAttack
{
	void Attack(BaseCharacter* attacker, BaseCharacter* characters) override;
};