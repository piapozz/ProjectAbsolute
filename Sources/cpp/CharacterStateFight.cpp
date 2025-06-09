#include "../header/CharacterStateFight.h"
#include "../header/BaseCharacter.h"
#include "../header/ObjectManager.h"
#include "../header/BaseAttack.h"


void CharacterStateFight::Update(BaseCharacter* character)
{
	ObjectManager& objectManager = ObjectManager::Instance();
	Vector2 attackerPos = character->GetPosition();

	_targetCharacter = selector->SelectTargets(character);

	// “¯‚¶‹æ‰æ‚É“G‘Î‘ÎÛ‚ª‚¢‚é‚©ŒŸõ
	BaseObject* attackerSection = objectManager.FindPosObject(attackerPos, ObjectType::SECTION);
	Vector2 sectionPosition = attackerSection->GetPosition();
	Vector2 sectionSize = attackerSection->GetSize();

	std::vector<BaseObject*> targetCharaList = objectManager.FindRectAllObject(sectionPosition, sectionSize, ObjectType::CHARACTER);
	
	Vector2 targetPosition = _targetCharacter[0]->GetPosition();
	BaseObject* targetSectionObject = objectManager.FindPosObject(targetPosition, ObjectType::SECTION);
	BaseSection* targetSection = dynamic_cast<BaseSection*>(targetSectionObject);

	// ‹æ‰æ‚É“G‘Î‘ÎÛ‚ª‚¢‚È‚©‚Á‚½‚ç
	if (targetCharaList.empty())
	{
		character->ChangeMoveState(targetSection, CharacterStateID::FIGHT);
		return;
	}

	int dx = targetPosition.x - attackerPos.x;
	BaseCharacter::AttackAction* attack = character->GetAttackAction()[0];
	int attackRange = attack->attackRange;

	// ŽË’öŠO
	if (abs(dx) > attackRange)
	{
		character->ChangeMoveState(targetPosition, CharacterStateID::FIGHT);
		return;
	} 
	// ŽË’ö“à
	else
	{
		// ŽŸ‚ÌUŒ‚‚Ü‚Å‚ÌƒN[ƒ‹ƒ^ƒCƒ€

		// UŒ‚
		if (attack)
		{
			attack->characterAttack->Attack(character);
		}
	}
	return;
}

void CharacterStateFight::Enter(BaseCharacter* character)
{
	character->color = FIGHT;
	character->stateID = CharacterStateID::FIGHT;
}

void CharacterStateFight::Exit(BaseCharacter* character)
{
	character->color = IDLE;
}