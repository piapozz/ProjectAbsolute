#include "../header/BaseEntity.h"

void BaseEntity::Init()
{
	// �}�X�^�[�f�[�^����ID�Q�ƂŃp�����[�^�[���擾
	hazardLevel = 0;
	maxRunawayCount = 3;
	runawayCount = maxRunawayCount;
}

void BaseEntity::Proc()
{
	
}

void BaseEntity::Draw()
{
	
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