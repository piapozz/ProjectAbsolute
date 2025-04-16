#include "../header/BaseEntity.h"

void BaseEntity::Init()
{
	// �}�X�^�[�f�[�^����ID�Q�ƂŃp�����[�^�[���擾
	_hazardLevel = 0;
	_maxRunawayCount = 3;
	_runawayCount = _maxRunawayCount;
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
	_runawayCount--;
	// �\���J�E���^�[��0�ɂȂ�����A�\���C�x���g�𔭐�������
	if (_runawayCount > 0) return;
	RunawayEvent();
}