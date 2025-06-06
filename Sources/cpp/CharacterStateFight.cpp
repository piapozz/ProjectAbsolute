#include "../header/CharacterStateFight.h"
#include "../header/BaseCharacter.h"
#include "../header/ObjectManager.h"
#include "../header/BaseAttack.h"


void CharacterStateFight::Update(BaseCharacter* character)
{
	ObjectManager& objectManager = ObjectManager::Instance();
	Vector2 attackerPos = character->GetPosition();

	_targetCharacter = selector->SelectTargets(character);

	// �@同じ区画に敵対対象がいるか検索
	BaseObject* attackerSection = objectManager.FindPosObject(attackerPos, ObjectType::SECTION);
	Vector2 sectionPosition = attackerSection->GetPosition();
	Vector2 sectionSize = attackerSection->GetSize();

	std::vector<BaseObject*> targetCharaList = objectManager.FindRectAllObject(sectionPosition, sectionSize, ObjectType::CHARACTER);
	
	// 区画に敵対対象がいなかったら
	if (targetCharaList.empty())
	{
		// �Aいないなら経路探索して同じ部屋まで移動
		// 移動が完了したら経路探索しなおす
		// character->Move(targetCharacter)
		return;
	}

	// �Aいるなら射程圏内まで部屋内移動
	// character->Move()

	// �@〜�Bの間に対象との距離を見て間合いなら攻撃する
	BaseAttack* attack = character->GetAttack();
	// attack->Attack(_targetCharacter);

	// (同じ区画内への攻撃ならこの前に同じ区画にいるか調べること)
}

void CharacterStateFight::Enter(BaseCharacter* character)
{

}

void CharacterStateFight::Exit(BaseCharacter* character)
{

}