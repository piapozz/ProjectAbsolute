#include "../header/BaseEgoEntity.h"

void BaseEgoEntity::Init(LayerSetting layerSetting)
{
	BaseEntity::Init(layerSetting);
	isRunaway = false;
}

void BaseEgoEntity::Proc()
{
	BaseEntity::Proc();

	// �s���̌���
	// �E�����ĂȂ��Ȃ�Ԃ�
	if (!isRunaway) return;
	// �����ɍU���Ώۂ����邩�m�F
	// ����Ȃ�X�e�[�g���U���Ɉڍs
	// ���Ȃ��Ȃ�X�e�[�g���ړ��ɕύX

}
