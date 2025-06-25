#include "../header/AttackSingle.h"

void AttackSingle::Attack(BaseCharacter* attacker, BaseCharacter* characters)
{
	if (attacker == nullptr) return;
	int attackDamage = attacker->GetAttackStatus().attack;
	Type attackType= attacker->GetAttackStatus().damageType;

	if(!characters->GetIsDead()) characters->TakeDamage(attackDamage, attackType);
}