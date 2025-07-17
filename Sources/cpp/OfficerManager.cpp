#include "../header/OfficerManager.h"
#include "../header/OfficerInitData.h"
#include "../header/ObjectFactory.h"
#include "../header/DataManager.h"

OfficerManager::OfficerManager()
{

}

OfficerManager::~OfficerManager()
{

}

void OfficerManager::Init()
{
	Transform sectionTransform = StageManager::Instance().GetRandomSection()->GetTransform();
	Vector2 sectionPosition = sectionTransform.position;
	Vector2 sectionScale = sectionTransform.scale;

	Vector2 position = Vector2(sectionPosition.x, sectionPosition.y - SECTION_SIZE_Y / 2);

	vector<OfficerInitData> officerDataList = DataManager::Instance().GetOfficerData();

	for (int i = 0, max = officerDataList.size(); i < max; i++)
	{
		AddOfficer(OfficerType::PLAYER, officerDataList[i], position);
	}

	// 職員がいない場合はゲームオーバー
	if (IsAllOfficerRestricted())
		DisplayGameOverUI();

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

vector<OfficerInitData> OfficerManager::GetAliveOfficerData()
{
	vector<OfficerInitData> aliveOfficerData;
	for (int i = 0, max = _officerList.size(); i < max; i++)
	{
		BaseOfficer* officer = _officerList[i];
		if (officer->GetIsDead()) continue;

		aliveOfficerData.push_back(officer->GetOfficerInitData());
	}

	return aliveOfficerData;
}

bool OfficerManager::IsAllOfficerRestricted()
{
	for (BaseOfficer* officer : _officerList)
	{
		if (officer && (!officer->GetIsRestricted())) return false;
	}
	return true;
}