#include "../header/BaseToolEntity.h"

void BaseToolEntity::Proc()
{
	// ツールが使用中なら処理を行う
	if (interactOfficerID < 0) return;

	// 種類によって処理を分ける
	switch (_toolType)
	{
		case ToolType::Single:
			break;
		case ToolType::Continue:
		case ToolType::Equip:
			// 使用中の処理
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

