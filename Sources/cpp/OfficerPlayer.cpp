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
	DrawFormatString(screenPos.x, screenPos.y - 30, GetColor(255, 255, 255), "HP:%d", health);
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

void DrawHpBar(int x, int y, int width, int height, int hp, int maxHp)
{
	int hpWidth = (int)((float)hp / maxHp * width);

	DrawBox(x, y, x + width, y + height, GetColor(100, 100, 100), TRUE);
	DrawBox(x, y, x + hpWidth, y + height, GetColor(255, 0, 0), TRUE);
	DrawBox(x - 1, y - 1, x + width + 1, y + height + 1, GetColor(255, 255, 255), FALSE);
}