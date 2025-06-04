#include "../header/OfficerManager.h"
#include "../header/OfficerInitData.h"
#include "../header/ObjectFactory.h"

OfficerManager::OfficerManager()
{

}

OfficerManager::~OfficerManager()
{

}

void OfficerManager::Init()
{
	OfficerInitData data;
	AddOfficer(OfficerType::PLAYER, data);
}

void OfficerManager::Proc()
{

}

void OfficerManager::Teardown()
{

}

BaseOfficer* OfficerManager::AddOfficer(OfficerType type, OfficerInitData data)
{
	int emptyIndex = -1;

	for (int i = 0; i < _officerList.size(); i++)
	{
		BaseOfficer* officer = _officerList[i];
		if (officer == nullptr || officer->GetOfficerType() == OfficerType::NONE)
		{
			emptyIndex = i;
			break;
		}
	}

	ObjectFactory& factory = ObjectFactory::Instance();
	int indexToUse = (emptyIndex == -1) ? _officerList.size() : emptyIndex;

	BaseOfficer* officer = nullptr;
	switch (type)
	{
		case OfficerType::PLAYER:
			officer = factory.CreateWithArgs<OfficerPlayer>(data, indexToUse);
			break;
		case OfficerType::MOB:
			officer = factory.CreateWithArgs<OfficerMob>(data, indexToUse);
			break;
		default:
			return nullptr;
	}
	if (!officer) return nullptr;


	if (emptyIndex == -1) _officerList.push_back(officer);
	
	else _officerList[emptyIndex] = officer;

	return officer;
}

void OfficerManager::MoveSelectedPlayer(std::vector<int> officerNumber)
{
	for (int i = 0, max = officerNumber.size();i < max;i++)
	{

	}
}