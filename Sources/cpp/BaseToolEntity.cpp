#include "../header/BaseToolEntity.h"

void BaseToolEntity::Init(LayerSetting layerSetting)
{
	BaseEntity::Init(layerSetting);
}

void BaseToolEntity::Proc()
{
	// �c�[�����g�p���Ȃ珈�����s��

	// ��ނɂ���ď����𕪂���
	switch (_toolType)
	{
		case ToolType::Single:
			break;
		case ToolType::Continue:
		case ToolType::Equip:
			// �g�p���̏���
			UseProc();
			break;
		default:
			break;
	}
}

void BaseToolEntity::Use(int userID)
{
	UseEvent();
}

void BaseToolEntity::Disuse()
{
	DisuseEvent();
}

