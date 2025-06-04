#include "../header/AttackNormal.h"
#include "../header/ObjectManager.h"

void AttackNormal::Attack(BaseCharacter* chara)
{
	// �U���Ώۂ�ێ�
	std::vector<BaseCharacter*> targetList;

	// �L��������U����,�^�C�v���擾
	int attackDamage = chara->GetAttackStatus().attack;
	Type attackType= chara->GetAttackStatus().damageType;

	// �U���L�������������G������
	CharacterGroup myGroup = chara->GetGroup();

	// �U�������n�_���v�Z
	Vector2 attackPos = GetLocation(chara->GetPosition());

	// �U���͈͓��̃L���������G
	std::vector<BaseObject*> characters;
	characters = GetHitBoxCharacters(attackPos);

	// �Ώۂ��i��
	for (int i = 0;i < characters.size();i++)
	{
		BaseCharacter* character = dynamic_cast<BaseCharacter*>(characters[i]);
		CharacterGroup characterGroup = character->GetGroup();

		// �ʂ̕����̃L�����N�^�[���U�����Ȃ�

		
		// �������U�����Ȃ�
		if (myGroup == characterGroup) continue;
		targetList.push_back(character);
	}

	// �U���Ώۂɑ΂��ă_���[�W��^����
	for (int i = 0;i < targetList.size();i++)
	{
		targetList[i]->TakeDamege(attackDamage, attackType);
	}

	// �I��
	return;
}