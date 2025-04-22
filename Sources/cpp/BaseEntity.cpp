#include "../header/BaseEntity.h"

void BaseEntity::Init()
{
	BaseCharacter::Init();
	// �}�X�^�[�f�[�^����ID�Q�ƂŃp�����[�^�[���擾
	hazardLevel = 0;
	maxRunawayCount = 3;
	runawayCount = maxRunawayCount;
}

void BaseEntity::Draw()
{
	DrawSphere3D(VGet(position.x, position.y, 0), 10, 32, GetColor(255, 0, 0), GetColor(0, 0, 0), FALSE);
}

void BaseEntity::Teardown()
{
	
}

void BaseEntity::DecreaseRunawayCount()
{
	// �\���J�E���^�[������������
	runawayCount--;
	// �\���J�E���^�[��0�ɂȂ�����A�\���C�x���g�𔭐�������
	if (runawayCount > 0) return;
	RunawayEvent();
}