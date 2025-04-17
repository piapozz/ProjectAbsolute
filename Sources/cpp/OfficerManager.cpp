#include "../header/OfficerManager.h"

OfficerManager::OfficerManager()
{

}

OfficerManager::~OfficerManager()
{

}

void OfficerManager::Init()
{
	//for (int i = 0; i < 3; i++)
	//{
	//	AddOfficer(OfficerType::PLAYER);
	//}
	for (int i = 0; i < DEFAULT_OFFICER_COUNT; i++)
	{
		AddOfficer(OfficerType::MOB);
	}

	for (int i = 0; i < _officerList.size(); i++)
	{
		float positionX = GetRand(500);
		Vector2 indexVector = {positionX, 0};
		_officerList[i]->SetHealth(100);
		_officerList[i]->SetMental(100);
		_officerList[i]->SetPosition(indexVector);
	}
}

void OfficerManager::Proc()
{

}

void OfficerManager::Teardown()
{

}

void OfficerManager::AddOfficer(OfficerType type)
{
	int emptyIndex = -1;

	// 空きを探す
	for (int i = 0; i < _officerList.size(); i++)
	{
		BaseOfficer* officer = _officerList[i];
		if (officer == nullptr || officer->GetOfficerType() == OfficerType::NONE)
		{
			emptyIndex = i;
			break;
		}
	}
	// Officerの生成
	BaseOfficer* officer = nullptr;
	switch (type)
	{
		case OfficerType::PLAYER:
			officer = new OfficerPlayer();
			break;
		case OfficerType::MOB:
			officer = new OfficerMob();
			break;
		default:
			return;
	}
	if (!officer) return;

	officer->Init(DEFAULT_OFFICER_POSITION, emptyIndex);
	ObjectManager::AddObject(officer);

	// 空きがなかったら新規に追加
	if (emptyIndex == -1)
	{
		_officerList.push_back(officer);
		return;
	}
	// 空きスロットに再利用として上書き
	_officerList[emptyIndex] = officer;
}

