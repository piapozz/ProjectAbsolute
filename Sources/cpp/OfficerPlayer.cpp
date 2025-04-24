#include "../header/OfficerPlayer.h"
#include "../header/BaseCharacterState.h"
#include "../header/OfficerInitData.h"

OfficerPlayer::OfficerPlayer()
{

}

OfficerPlayer::~OfficerPlayer()
{

}

void OfficerPlayer::Init(OfficerInitData data, int setOfficerID)
{
	BaseOfficer::Init(data, setOfficerID);
	_officerType = OfficerType::PLAYER;
	layer = Layer::PLAYER;
	slider = new UISlider;
	Vector2 pos(position.x, position.y + (objectSize.y / 2));
	slider->Init(pos, Vector2(objectSize.x, objectSize.y/4));
	slider->SetActive(true);
	slider->SetText("HP");
	slider->SetLayer(Layer::NONE_INTERACT);
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
	// ¶ã‚ÉUI‚ğ•`‰æ


}
