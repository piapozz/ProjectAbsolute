#include "../header/BaseAttack.h"
#include "../header/ObjectManager.h"

//void BaseAttack::Attack(BaseCharacter* chara, Vector2 attackPos, Vector2 attackSize)
//{
//	// ƒLƒƒƒ‰‚©‚çUŒ‚—Í,ƒ^ƒCƒv‚ğæ“¾
//	int attackDamage = chara->GetAttackStatus().attack;
//	Type attackType= chara->GetAttackStatus().damageType;
//
//	// UŒ‚ƒLƒƒƒ‰‚ª–¡•û‚©“G‚©”»•Ê
//	CharacterGroup myGroup = chara->GetGroup();
//
//	// UŒ‚”ÍˆÍ“à‚ÌƒLƒƒƒ‰‚ğõ“G
//	std::vector<BaseObject*> characters;
//	characters = ObjectManager::instance->FindRectObject(attackPos, attackSize, ObjectType::CHARACTER);
//
//	// –¡•û‚Í”»’è‚µ‚È‚¢
//	for (int i = 0;i < characters.size();i++)
//	{
//		BaseCharacter* character = dynamic_cast<BaseCharacter*>(characters[i]);
//		CharacterGroup characterGroup = character->GetGroup();
//		if (myGroup == characterGroup) continue;
//		targetList.push_back(character);
//	}
//
//	// UŒ‚‘ÎÛ‚É‘Î‚µ‚Äƒ_ƒ[ƒW‚ğ—^‚¦‚é
//	for (int i = 0;i < targetList.size();i++)
//	{
//		targetList[i]->TakeDamege(attackDamage, attackType);
//	}
//
//	// I—¹
//	return;
//}

void BaseAttack::Attack(BaseCharacter* chara)
{
	// UŒ‚‘ÎÛ‚ğ•Û
	std::vector<BaseCharacter*> targetList;

	// ƒLƒƒƒ‰‚©‚çUŒ‚—Í,ƒ^ƒCƒv‚ğæ“¾
	int attackDamage = chara->GetAttackStatus().attack;
	Type attackType= chara->GetAttackStatus().damageType;

	// UŒ‚ƒLƒƒƒ‰‚ª–¡•û‚©“G‚©”»•Ê
	CharacterGroup myGroup = chara->GetGroup();

	// UŒ‚”ÍˆÍ“à‚ÌƒLƒƒƒ‰‚ğõ“G
	Vector2 attackPos = chara->GetPosition();
	std::vector<BaseObject*> characters;
	characters = GetHitBoxCharacters(attackPos);

	// –¡•û‚Í”»’è‚µ‚È‚¢
	for (int i = 0;i < characters.size();i++)
	{
		BaseCharacter* character = dynamic_cast<BaseCharacter*>(characters[i]);
		CharacterGroup characterGroup = character->GetGroup();
		if (myGroup == characterGroup) continue;
		targetList.push_back(character);
	}

	// UŒ‚‘ÎÛ‚É‘Î‚µ‚Äƒ_ƒ[ƒW‚ğ—^‚¦‚é
	for (int i = 0;i < targetList.size();i++)
	{
		targetList[i]->TakeDamege(attackDamage, attackType);
	}

	return;
}

Vector2 BaseAttack::GetLocation(Vector2 position)
{
	return position + hitBoxSpace;
}

std::vector<BaseObject*> BaseAttack::GetHitBoxCharacters(Vector2 location)
{
	std::vector<BaseObject*> characters;
	characters = ObjectManager::instance->FindRectObject(location, hitBoxSize, ObjectType::CHARACTER);
	return characters;
}