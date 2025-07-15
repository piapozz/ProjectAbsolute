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
	Transform sectionTransform = StageManager::Instance().GetRandomSection()->GetTransform();
	Vector2 sectionPosition = sectionTransform.position;
	Vector2 sectionScale = sectionTransform.scale;

	Vector2 position = Vector2(sectionPosition.x, sectionPosition.y - SECTION_SIZE_Y / 2);
	AddOfficer(OfficerType::PLAYER, data, position);
	AddOfficer(OfficerType::PLAYER, data, position);
	//AddOfficer(OfficerType::PLAYER, data, position);
	//AddOfficer(OfficerType::PLAYER, data, position);
	//AddOfficer(OfficerType::PLAYER, data, position);
	//AddOfficer(OfficerType::PLAYER, data, position);
	//AddOfficer(OfficerType::PLAYER, data, position);
	//AddOfficer(OfficerType::PLAYER, data, position);
	//AddOfficer(OfficerType::PLAYER, data, position);
	//AddOfficer(OfficerType::PLAYER, data, position);
	//AddOfficer(OfficerType::PLAYER, data, position);
	//AddOfficer(OfficerType::PLAYER, data, position);
	//AddOfficer(OfficerType::PLAYER, data, position);
	//AddOfficer(OfficerType::PLAYER, data, position);
	//AddOfficer(OfficerType::PLAYER, data, position);

	//sectionTransform = StageManager::Instance().GetRandomSection()->GetTransform();
	//sectionPosition = sectionTransform.position;
	//sectionScale = sectionTransform.scale;

	//position = Vector2(sectionPosition.x, sectionPosition.y - SECTION_SIZE_Y / 2);
	//AddOfficer(OfficerType::MOB, data, position);

	//sectionTransform = StageManager::Instance().GetRandomSection()->GetTransform();
	//sectionPosition = sectionTransform.position;
	//sectionScale = sectionTransform.scale;

	//position = Vector2(sectionPosition.x, sectionPosition.y - SECTION_SIZE_Y / 2);
	//AddOfficer(OfficerType::MOB, data, position);

	//sectionTransform = StageManager::Instance().GetRandomSection()->GetTransform();
	//sectionPosition = sectionTransform.position;
	//sectionScale = sectionTransform.scale;

	//position = Vector2(sectionPosition.x, sectionPosition.y - SECTION_SIZE_Y / 2);
	//AddOfficer(OfficerType::MOB, data, position);
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
			officer = factory.CreateWithArgs<OfficerPlayer>(data, indexToUse, layerSetting, position);
			break;
		case OfficerType::MOB:
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