#include "../header/OfficerMob.h"
#include "../header/BaseCharacterState.h"
#include "../header/OfficerInitData.h"

OfficerMob::OfficerMob()
{

}

OfficerMob::~OfficerMob()
{

}

void OfficerMob::Init(OfficerInitData data, int setOfficerID)
{
	BaseOfficer::Init(data, setOfficerID);
	SetImpossible(false);
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
}

void OfficerMob::Teardown()
{
	BaseOfficer::Teardown();
}