#include "../header/CharacterStateFight.h"
#include "../header/BaseCharacter.h"
#include "../header/ObjectManager.h"
#include "../header/BaseAttack.h"


void CharacterStateFight::Update(BaseCharacter* character)
{
	ObjectManager& objectManager = ObjectManager::Instance();
	Vector2 attackerPos = character->GetPosition();

	_targetCharacter = selector->SelectTargets(character);

	// �������ɓG�ΑΏۂ����邩����
	BaseObject* attackerSection = objectManager.FindPosObject(attackerPos, ObjectType::SECTION);
	Vector2 sectionPosition = attackerSection->GetPosition();
	Vector2 sectionSize = attackerSection->GetSize();

	std::vector<BaseObject*> targetCharaList = objectManager.FindRectAllObject(sectionPosition, sectionSize, ObjectType::CHARACTER);
	
	Vector2 targetPosition = _targetCharacter[0]->GetPosition();
	BaseObject* targetSectionObject = objectManager.FindPosObject(targetPosition, ObjectType::SECTION);
	BaseSection* targetSection = dynamic_cast<BaseSection*>(targetSectionObject);

	// ���ɓG�ΑΏۂ����Ȃ�������
	if (targetCharaList.empty())
	{
		character->ChangeMoveState(targetSection, CharacterStateID::FIGHT);
		return;
	}

	int dx = targetPosition.x - attackerPos.x;
	BaseCharacter::AttackAction* attack = character->GetAttackAction()[0];
	int attackRange = attack->attackRange;

	// �˒��O
	if (abs(dx) > attackRange)
	{
		character->ChangeMoveState(targetPosition, CharacterStateID::FIGHT);
		return;
	} 
	// �˒���
	else
	{
		// ���̍U���܂ł̃N�[���^�C��

		// �U��
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