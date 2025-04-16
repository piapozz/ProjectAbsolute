#include "../header/OfficerPlayer.h"

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
	DrawSphere3D(spherePosition, 50, 32, GetColor(255, 0, 0), GetColor(0, 0, 0), FALSE);
}

void OfficerPlayer::Teardown()
{
	BaseOfficer::Teardown();
}