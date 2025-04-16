#include "../header/OfficerMob.h"

OfficerMob::OfficerMob()
{

}

OfficerMob::~OfficerMob()
{

}

void OfficerMob::Init()
{
	BaseOfficer::Init();
	_officerType = OfficerType::MOB;
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