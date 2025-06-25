#include "../header/AttackBetweenCharacters.h"
#include "../header/ObjectManager.h"

void AttackBetweenCharacters::Attack(BaseCharacter* attacker, BaseCharacter* characters)
{
	if (!attacker || !characters) return;

	// 攻撃情報取得
	int damage = attacker->GetAttackStatus().attack;
	Type damageType = attacker->GetAttackStatus().damageType;
	CharacterGroup myGroup = attacker->GetGroup();
	CharacterGroup targetGroup = characters->GetGroup();

	// 座標取得
	Vector2 attackerPos = attacker->GetPosition();
	Vector2 targetPos = characters->GetPosition();

	int minX = attackerPos.x;
	int maxX = targetPos.x;
	if (attackerPos.x > targetPos.x)
	{
		minX = targetPos.x;
		maxX = attackerPos.x;
	}

	int top = attackerPos.y - 50;
	int bottom = attackerPos.y + 50;

	int width = maxX - minX;
	if (width == 0) width = 1;

	Vector2 areaPos;
	areaPos.x = minX + width / 2;
	areaPos.y = (top + bottom) / 2;

	Vector2 areaSize;
	areaSize.x = width;
	areaSize.y = bottom - top;

	// 範囲内のキャラクター取得
	ObjectManager& objectManager = ObjectManager::Instance();
	std::vector<BaseObject*> hitCharacterList = objectManager.FindRectAllObject(areaPos, areaSize, ObjectType::CHARACTER);

	for (int i = 0; i < hitCharacterList.size(); i++)
	{
		BaseCharacter* hitCharacter = dynamic_cast<BaseCharacter*>(hitCharacterList[i]);

		if (!hitCharacter) continue;
		if (hitCharacter->GetIsDead())continue;
		if (hitCharacter->GetGroup() != targetGroup) continue;
		hitCharacter->TakeDamage(damage, damageType);
	}
}