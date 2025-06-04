#include "../header/BaseAttack.h"
#include "../header/BaseCharacter.h"
#include "../header/ObjectManager.h"

//void BaseAttack::Attack(BaseCharacter* chara)
//{
//	// �U���Ώۂ�ێ�
//	std::vector<BaseCharacter*> targetList;
//
//	// �L��������U����,�^�C�v���擾
//	int attackDamage = chara->GetAttackStatus().attack;
//	Type attackType= chara->GetAttackStatus().damageType;
//
//	// �U���L�������������G������
//	CharacterGroup myGroup = chara->GetGroup();
//
//	// �U���͈͓��̃L���������G
//	Vector2 attackPos = chara->GetPosition();
//	std::vector<BaseObject*> characters;
//	characters = GetHitBoxCharacters(attackPos);
//
//	// �����͔��肵�Ȃ�
//	for (int i = 0;i < characters.size();i++)
//	{
//		BaseCharacter* character = dynamic_cast<BaseCharacter*>(characters[i]);
//		CharacterGroup characterGroup = character->GetGroup();
//		if (myGroup == characterGroup) continue;
//		targetList.push_back(character);
//	}
//
//	// �U���Ώۂɑ΂��ă_���[�W��^����
//	for (int i = 0;i < targetList.size();i++)
//	{
//		targetList[i]->TakeDamege(attackDamage, attackType);
//	}
//
//	return;
//}
//
//Vector2 BaseAttack::GetLocation(Vector2 position)
//{
//	return position + hitBoxSpace;
//}
//
//std::vector<BaseObject*> BaseAttack::GetHitBoxCharacters(Vector2 location)
//{
//	std::vector<BaseObject*> characters;
//	characters = ObjectManager::instance->FindRectObject(location, hitBoxSize, ObjectType::CHARACTER);
//	return characters;
//}

void BaseAttack::Attack(BaseCharacter* attacker) 
{
	std::vector<BaseCharacter*> targets = targetSelector->SelectTargets(attacker);
	for (int i = 0; i < targets.size(); i++)
	{
		int attackDamage = attacker->GetAttackStatus().attack;
		Type attackType= attacker->GetAttackStatus().damageType;
		targets[i]->TakeDamage(attackDamage, attackType);
	}
}