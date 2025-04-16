#include "../header/BaseToolEntity.h"

void BaseToolEntity::Proc()
{
	// �c�[�����g�p���Ȃ珈�����s��
	if (interactOfficerID < 0) return;

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
	interactOfficerID = userID;
	UseEvent(interactOfficerID);
}

void BaseToolEntity::Disuse()
{
	DisuseEvent(interactOfficerID);
	interactOfficerID = -1;
}

