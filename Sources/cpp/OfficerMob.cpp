#include "../header/OfficerMob.h"
#include "../header/BaseOfficerState.h"

OfficerMob::OfficerMob()
{

}

OfficerMob::~OfficerMob()
{

}

void OfficerMob::Init(Vector2 setPosition, int setOfficerID)
{
	BaseOfficer::Init(setPosition, setOfficerID);
	_officerType = OfficerType::MOB;
	layer = Layer::PLAYER;

	startTime = GetNowCount();
	now = startTime;
}

void OfficerMob::Proc()
{
	BaseOfficer::Proc();
	//now = GetNowCount();
	//int elapsed = now - startTime;

	//if (elapsed >= 3000) // 3ïbåoâﬂÇµÇΩÇÁ
	//{
	//	int state = GetRand((int)OfficerStateID::MAX - 1);
	//	ChangeState((OfficerStateID)state);
	//	startTime = GetNowCount();
	//} 
}

void OfficerMob::Draw()
{
	BaseOfficer::Draw();

	VECTOR spherePosition;
	spherePosition.x = position.x;
	spherePosition.y = position.y;
	spherePosition.z = 0;
	DrawSphere3D(spherePosition, 10, 32, color, GetColor(0, 0, 0), TRUE);
}

void OfficerMob::Teardown()
{
	BaseOfficer::Teardown();
}