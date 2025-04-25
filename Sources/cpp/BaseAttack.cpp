#include "../header/BaseAttack.h"
#include "../header/ObjectManager.h"

void BaseAttack::Attack(BaseCharacter* chara, Vector2 attackPos, Vector2 attackSize)
{
	// キャラから攻撃力,タイプを取得

	// 攻撃キャラが味方か敵か判別

	// 攻撃範囲内のキャラを索敵
	std::vector<BaseObject*> characters;
	characters = ObjectManager::instance->FindRectObject(attackPos, attackSize, ObjectType::CHARACTER);

	// 味方は判定しない

	// 敵に対してダメージを与える

	// 終了
}