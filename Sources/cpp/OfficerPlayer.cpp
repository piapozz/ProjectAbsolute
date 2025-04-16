#include "../header/OfficerPlayer.h"

OfficerPlayer::OfficerPlayer()
{

}

OfficerPlayer::~OfficerPlayer()
{

}

void OfficerPlayer::Init()
{
	BaseOfficer::Init();
	_officerType = OfficerType::PLAYER;
}

void OfficerPlayer::Proc()
{
	BaseOfficer;;Init();
}

void OfficerPlayer::Draw()
{
	BaseOfficer::Draw();
}

void OfficerPlayer::Teardown()
{
	BaseOfficer::Teardown();
}