#include "../header/OfficerPlayer.h"
#include "../header/BaseCharacterState.h"
#include "../header/PhaseMain.h"
#include "../header/ObjectFactory.h"

void OfficerPlayer::Init(OfficerInitData data, int setOfficerID)
{
	BaseOfficer::Init(data, setOfficerID);
	_groupType = CharacterGroup::OFFICER;
	_officerType = OfficerType::PLAYER;
	Transform transformWorld = transform.GetWorldTransform();
	Vector2 position = transformWorld.position;
	Vector2 scale = transformWorld.scale;
	Vector2 pos(position.x, position.y + (scale.y / 2));
	LayerSetting UILayerSetting = {true, false, Layer::MIDDLE};
	Transform transform = Transform(pos + Vector2(0, scale.y), Vector2(scale.x, scale.y / 4));
	slider = ObjectFactory::Instance().CreateWithArgs<UISlider>(transform, UILayerSetting);
	slider->SetActive(true);
	slider->SetText("HP");
	slider->SetColor(255, 0, 0);

	SetImpossible(true);
}

void OfficerPlayer::Proc()
{
	BaseOfficer::Proc();
}

void OfficerPlayer::Draw()
{
	BaseOfficer::Draw();

	Transform transformWorld = transform.GetWorldTransform();
	Vector2 position = transformWorld.position;
	Vector2 scale = transformWorld.scale;
	VECTOR worldPos = {position.x, position.y, 0};
	VECTOR screenPos = ConvWorldPosToScreenPos(worldPos);

	Vector2 pos(position.x, position.y + (scale.y / 2));
	slider->SetPos(pos + Vector2(0, scale.y));
	slider->SetValue((float)(health / maxHealth));
}

void OfficerPlayer::Teardown()
{
	BaseOfficer::Teardown();
}

void OfficerPlayer::ClickEvent()
{
	// çÏã∆íÜÇ»ÇÁâΩÇ‡ÇµÇ»Ç¢
	if (stateID == CharacterStateID::OPERATION) return;
	// ç∂è„Ç…UIÇï`âÊ
	std::vector<OfficerPlayer*>& selectOfficerList = PhaseMain::GetSelectOfficerList();
	selectOfficerList.clear();
	selectOfficerList.push_back(this);
}
