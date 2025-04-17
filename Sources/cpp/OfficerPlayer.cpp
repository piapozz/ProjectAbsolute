#include "../header/OfficerPlayer.h"
#include "../header/BaseOfficerState.h"

OfficerPlayer::OfficerPlayer()
{

}

OfficerPlayer::~OfficerPlayer()
{

}

void OfficerPlayer::Init(Vector2 setPosition, int setOfficerID)
{
	BaseOfficer::Init(setPosition, setOfficerID);
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

	VECTOR spherePosition;
	spherePosition.x = position.x;
	spherePosition.y = position.y;
	spherePosition.z = 0;
	DrawSphere3D(spherePosition, 10, 32, color, GetColor(0, 0, 0), FALSE);
}

void OfficerPlayer::Teardown()
{
	BaseOfficer::Teardown();
}

void OfficerPlayer::MoveToTargetPos(std::vector<std::vector<int>> stageData, Vector2 start, Vector2 goal)
{
	StateArgs* args = new StateArgs();
	args->targetPosList = RouteSearcher::RouteSearch(stageData, start, goal);
	ChangeState(OfficerStateID::OFFICER_MOVE, args);
}