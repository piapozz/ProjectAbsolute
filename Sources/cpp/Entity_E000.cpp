#include "../header/Entity_E000.h"

void Entity_E000::Init(LayerSetting layerSetting)
{
	BaseEgoEntity::Init(layerSetting);
}

void Entity_E000::EndOperationEvent(int successCount)
{
	// ��ƂȂ珈��
	if (_currentOperationType != Type::PALE) return;

	// �\���J�E���^�[�����炷
	DecreaseRunawayCount();
}