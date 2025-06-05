#include "../header/OfficerPlayer.h"
#include "../header/BaseCharacterState.h"
#include "../header/PhaseMain.h"
#include "../header/ObjectFactory.h"

void OfficerPlayer::Init(OfficerInitData data, int setOfficerID)
{
	BaseOfficer::Init(data, setOfficerID);
	_officerType = OfficerType::PLAYER;
	Vector2 pos(position.x, position.y + (objectSize.y / 2));
	LayerSetting UILayerSetting = {true, false, Layer::MIDDLE};
	slider = ObjectFactory::Instance().CreateWithArgs<UISlider>(pos, Vector2(objectSize.x, objectSize.y/4), UILayerSetting);
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

	VECTOR worldPos = {position.x, position.y, 0};
	VECTOR screenPos = ConvWorldPosToScreenPos(worldPos);

	Vector2 pos(position.x, position.y + (objectSize.y / 2));
	slider->SetPos(pos);
	slider->SetValue((float)(health / maxHealth));
}

void OfficerPlayer::Teardown()
{
	BaseOfficer::Teardown();
}

void OfficerPlayer::ClickEvent()
{
	// ç∂è„Ç…UIÇï`âÊ
	std::vector<OfficerPlayer*>& selectOfficerList = PhaseMain::GetSelectOfficerList();
	selectOfficerList.clear();
	selectOfficerList.push_back(this);
}
