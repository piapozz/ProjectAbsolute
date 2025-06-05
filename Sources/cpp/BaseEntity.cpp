#include "../header/BaseEntity.h"
#include "../header/UIButton.h"
#include <cmath>

void BaseEntity::Init(LayerSetting layerSetting)
{
	BaseCharacter::Init(layerSetting);
	// �}�X�^�[�f�[�^����ID�Q�ƂŃp�����[�^�[���擾
	hazardLevel = 0;
	maxRunawayCount = 3;
	runawayCount = maxRunawayCount;
}

void BaseEntity::Proc()
{
	BaseCharacter::Proc();
}

void BaseEntity::Draw()
{
	VECTOR pos[3];
	for (int i = 0; i < 3; i++)
	{
		float angle = 2.0f / 3.0f * DX_PI * i;
		pos[i] = VGet(position.x + cos(angle) * 30, position.y + sin(angle) * 30, 0);
	}

	DrawTriangle3D(pos[0], pos[1], pos[2], GetColor(255, 255, 255), false);
}

void BaseEntity::Teardown()
{
	
}

void BaseEntity::DecreaseRunawayCount()
{
	// �\���J�E���^�[������������
	runawayCount--;
	if (runawayCount < 0) runawayCount = 0;
	_pRunawayUI->SetText(std::to_string(runawayCount));
	// �\���J�E���^�[��0�ɂȂ�����A�\���C�x���g�𔭐�������
	if (runawayCount > 0) return;
	RunawayEvent();
}

void BaseEntity::SetRunawayUI(UIButton* setUI)
{
	_pRunawayUI = setUI;
	_pRunawayUI->SetText(std::to_string(runawayCount));
}