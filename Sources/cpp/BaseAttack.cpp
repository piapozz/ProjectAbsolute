#include "../header/BaseAttack.h"
#include "../header/ObjectManager.h"

void BaseAttack::Attack(BaseCharacter* chara, Vector2 attackPos, Vector2 attackSize)
{
	// �L��������U����,�^�C�v���擾

	// �U���L�������������G������

	// �U���͈͓��̃L���������G
	std::vector<BaseObject*> characters;
	characters = ObjectManager::instance->FindRectObject(attackPos, attackSize, ObjectType::CHARACTER);

	// �����͔��肵�Ȃ�

	// �G�ɑ΂��ă_���[�W��^����

	// �I��
}