#include "../header/OfficerMob.h"

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
}

void OfficerMob::Proc()
{
	BaseOfficer::Proc();
}

void OfficerMob::Draw()
{
	BaseOfficer::Draw();

	VECTOR spherePosition;
	spherePosition.x = position.x;
	spherePosition.y = position.y;
	spherePosition.z = 0;
	DrawSphere3D(spherePosition, 50, 32, GetColor(255, 255, 255), GetColor(0, 0, 0), TRUE);
}

void OfficerMob::Teardown()
{
	BaseOfficer::Teardown();
}