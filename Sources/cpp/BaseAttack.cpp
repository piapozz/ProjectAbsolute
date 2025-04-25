#include "../header/BaseAttack.h"
#include "../header/ObjectManager.h"



void BaseAttack::Attack(BaseCharacter* chara, Vector2 attackPos, Vector2 attackSize)
{
	// キャラから攻撃力,タイプを取得
	int attackDamage = chara->GetAttackStatus().attack;
	Type attackType= chara->GetAttackStatus().damageType;

	// 攻撃キャラが味方か敵か判別
	CharacterGroup myGroup = chara->GetGroup();

	// 攻撃範囲内のキャラを索敵
	std::vector<BaseObject*> characters;
	characters = ObjectManager::instance->FindRectObject(attackPos, attackSize, ObjectType::CHARACTER);

	// 味方は判定しない
	for (int i = 0;i < characters.size();i++)
	{
		BaseCharacter* character = dynamic_cast<BaseCharacter*>(characters[i]);
		CharacterGroup characterGroup = character->GetGroup();
		if (myGroup == characterGroup) continue;
		targetList.push_back(character);
	}

	// 攻撃対象に対してダメージを与える
	for (int i = 0;i < targetList.size();i++)
	{
		targetList[i]->TakeDamege(attackDamage, attackType);
	}

	// 終了
	return;
}