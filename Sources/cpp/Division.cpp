#include "../header/Division.h"
#include "../header/BaseEntity.h"
#include "../header/SecureRoom.h"

std::vector<BaseSection*> Division::GetRoomList()
{
	std::vector<BaseSection*> result;

	for (BaseSection* section : _roomList)
	{
		if (section->GetSectionType() == SectionType::CONNECT ||
			section->GetSectionType() == SectionType::SECURE)
			continue;
		result.push_back(section);
	}

return result;
}

BaseSection* Division::GetRandomSection()
{
	std::vector<BaseSection*> room = GetRoomList();
	int size = room.size();
	if (size == 0)
		return nullptr;
	int rand = GetRand(size - 1);
	return room[rand];
}

void Division::SetEntity(BaseEntity* entity, int index)
{
	if (index < 0 || index >= _secureRoomList.size())
	{
		// インデックスが範囲外の場合は何もしない
		return;
	}

	_secureRoomList[index]->SetEntity(entity);
}