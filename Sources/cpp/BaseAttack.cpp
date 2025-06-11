#include "../header/BaseAttack.h"
#include "../header/BaseCharacter.h"
#include "../header/ObjectManager.h"

void BaseAttack::Attack(BaseCharacter* attacker) 
{
	std::vector<BaseCharacter*> targets = targetSelector->SelectTargets(attacker);
	for (int i = 0; i < targets.size(); i++)
	{
		int attackDamage = attacker->GetAttackStatus().attack;
		Type attackType= attacker->GetAttackStatus().damageType;
		targets[i]->TakeDamage(attackDamage, attackType);
	}
}