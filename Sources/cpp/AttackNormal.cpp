#include "../header/AttackNormal.h"
#include "../header/ObjectManager.h"

//void AttackNormal::Attack(BaseCharacter* chara)
//{
//	// 攻撃対象を保持
//	std::vector<BaseCharacter*> targetList;
//
//	// キャラから攻撃力,タイプを取得
//	int attackDamage = chara->GetAttackStatus().attack;
//	Type attackType= chara->GetAttackStatus().damageType;
//
//	// 攻撃キャラが味方か敵か判別
//	CharacterGroup myGroup = chara->GetGroup();
//
//	// 攻撃発生地点を計算
//	Vector2 attackPos = GetLocation(chara->GetPosition());
//
//	// 攻撃範囲内のキャラを索敵
//	std::vector<BaseObject*> characters;
//	characters = GetHitBoxCharacters(attackPos);
//
//	// 対象を絞る
//	for (int i = 0;i < characters.size();i++)
//	{
//		BaseCharacter* character = dynamic_cast<BaseCharacter*>(characters[i]);
//		CharacterGroup characterGroup = character->GetGroup();
//
//		// 別の部屋のキャラクターを攻撃しない
//
//		
//		// 味方を攻撃しない
//		if (myGroup == characterGroup) continue;
//		targetList.push_back(character);
//	}
//
//	// 攻撃対象に対してダメージを与える
//	for (int i = 0;i < targetList.size();i++)
//	{
//		targetList[i]->TakeDamege(attackDamage, attackType);
//	}
//
//	// 終了
//	return;
//}

void AttackNormal::Attack(BaseCharacter* attacker)
{

}
