#include "../header/AttackNormal.h"
#include "../header/ObjectManager.h"

void AttackNormal::Attack(BaseCharacter* chara)
{
	// UŒ‚‘ÎÛ‚ğ•Û
	std::vector<BaseCharacter*> targetList;

	// ƒLƒƒƒ‰‚©‚çUŒ‚—Í,ƒ^ƒCƒv‚ğæ“¾
	int attackDamage = chara->GetAttackStatus().attack;
	Type attackType= chara->GetAttackStatus().damageType;

	// UŒ‚ƒLƒƒƒ‰‚ª–¡•û‚©“G‚©”»•Ê
	CharacterGroup myGroup = chara->GetGroup();

	// UŒ‚”­¶’n“_‚ğŒvZ
	Vector2 attackPos = GetLocation(chara->GetPosition());

	// UŒ‚”ÍˆÍ“à‚ÌƒLƒƒƒ‰‚ğõ“G
	std::vector<BaseObject*> characters;
	characters = GetHitBoxCharacters(attackPos);

	// ‘ÎÛ‚ği‚é
	for (int i = 0;i < characters.size();i++)
	{
		BaseCharacter* character = dynamic_cast<BaseCharacter*>(characters[i]);
		CharacterGroup characterGroup = character->GetGroup();

		// •Ê‚Ì•”‰®‚ÌƒLƒƒƒ‰ƒNƒ^[‚ğUŒ‚‚µ‚È‚¢

		
		// –¡•û‚ğUŒ‚‚µ‚È‚¢
		if (myGroup == characterGroup) continue;
		targetList.push_back(character);
	}

	// UŒ‚‘ÎÛ‚É‘Î‚µ‚Äƒ_ƒ[ƒW‚ğ—^‚¦‚é
	for (int i = 0;i < targetList.size();i++)
	{
		targetList[i]->TakeDamege(attackDamage, attackType);
	}

	// I—¹
	return;
}