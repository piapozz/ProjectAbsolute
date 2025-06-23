#include "../header/OfficerManager.h"
#include "../header/OfficerInitData.h"
#include "../header/ObjectFactory.h"

OfficerManager::OfficerManager()
{

}

OfficerManager::~OfficerManager()
{

}

void OfficerManager::Init(StageManager* stageManager)
{
	OfficerInitData data;
	Vector2 position = stageManager->GetRandomSection()->GetTransform().position;
	AddOfficer(OfficerType::PLAYER, data, position);
	AddOfficer(OfficerType::PLAYER, data, position);
	AddOfficer(OfficerType::PLAYER, data, position);
	AddOfficer(OfficerType::PLAYER, data, position);
	position = stageManager->GetRandomSection()->GetTransform().position;
	AddOfficer(OfficerType::MOB, data, position);
}

void OfficerManager::Proc()
{

}

void OfficerManager::Teardown()
{

}

BaseOfficer* OfficerManager::AddOfficer(OfficerType type, OfficerInitData data, Vector2 position)
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
	LayerSetting layerSetting = {true, true, Layer::MIDDLE};
	switch (type)
	{
		case OfficerType::PLAYER:
			layerSetting = {true, true, Layer::MIDDLE};
			officer = factory.CreateWithArgs<OfficerPlayer>(data, indexToUse, layerSetting, position);
			break;
		case OfficerType::MOB:
			layerSetting = {true, false, Layer::MIDDLE};
			officer = factory.CreateWithArgs<OfficerMob>(data, indexToUse, layerSetting, position);
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