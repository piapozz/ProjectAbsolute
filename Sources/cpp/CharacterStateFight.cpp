#include "../header/CharacterStateFight.h"
#include "../header/BaseCharacter.h"
#include "../header/ObjectManager.h"
#include "../header/BaseAttack.h"


void CharacterStateFight::Update(BaseCharacter* character)
{
	ObjectManager& objectManager = ObjectManager::Instance();
	Vector2 attackerPos = character->GetPosition();

	_targetCharacter = selector->SelectTargets(character);

	// �@�������ɓG�ΑΏۂ����邩����
	BaseObject* attackerSection = objectManager.FindPosObject(attackerPos, ObjectType::SECTION);
	Vector2 sectionPosition = attackerSection->GetPosition();
	Vector2 sectionSize = attackerSection->GetSize();

	std::vector<BaseObject*> targetCharaList = objectManager.FindRectAllObject(sectionPosition, sectionSize, ObjectType::CHARACTER);
	
	// ���ɓG�ΑΏۂ����Ȃ�������
	if (targetCharaList.empty())
	{
		// �A���Ȃ��Ȃ�o�H�T�����ē��������܂ňړ�
		// �ړ�������������o�H�T�����Ȃ���
		// character->Move(targetCharacter)
		return;
	}

	// �A����Ȃ�˒������܂ŕ������ړ�
	// character->Move()

	// �@�`�B�̊ԂɑΏۂƂ̋��������Ċԍ����Ȃ�U������
	BaseAttack* attack = character->GetAttack();
	// attack->Attack(_targetCharacter);

	// (���������ւ̍U���Ȃ炱�̑O�ɓ������ɂ��邩���ׂ邱��)
}

void CharacterStateFight::Enter(BaseCharacter* character)
{

}

void CharacterStateFight::Exit(BaseCharacter* character)
{

}