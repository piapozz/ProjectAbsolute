#include "../header/OfficerPlayer.h"
#include "../header/BaseOfficerState.h"
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
	Vector2 pos(position.x, position.y + objectSize.y);
	slider->Init(pos, Vector2(objectSize.x, objectSize.y/4));
	slider->SetActive(true);
	slider->SetSliderText("HP");
	slider->SetLayer(Layer::DEBUG);
	slider->SetColor(255, 0, 0);
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

	DrawFormatString(0, 0, GetColor(255, 255, 255),"Player Pos: X=%.2f Y=%.2f", position.x, position.y);

	slider->SetValue((float)(health / maxHealth));
}

void OfficerPlayer::Teardown()
{
	BaseOfficer::Teardown();
}

void OfficerPlayer::ClickEvent()
{
	// ç∂è„Ç…UIÇï`âÊ


}

void OfficerPlayer::MoveToTargetPos(std::vector<Vector2> routeList)
{
	StateArgs* args = new StateArgs();
	args->targetPosList = routeList;
	ChangeState(OfficerStateID::OFFICER_MOVE, args);
}
