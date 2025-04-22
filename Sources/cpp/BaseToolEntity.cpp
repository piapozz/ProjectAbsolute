#include "../header/BaseToolEntity.h"

void BaseToolEntity::Init()
{
	BaseEntity::Init();
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

