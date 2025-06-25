#include "../header/BaseAttack.h"
#include "../header/BaseCharacter.h"
#include "../header/ObjectManager.h"

void BaseAttack::Attack(BaseCharacter* attacker, BaseCharacter* characters)
{
	if (attacker == nullptr) return;
	int attackDamage = attacker->GetAttackStatus().attack;
	Type attackType= attacker->GetAttackStatus().damageType;

	characters->TakeDamage(attackDamage, attackType);
}