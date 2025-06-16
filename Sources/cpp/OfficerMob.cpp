#include "../header/OfficerMob.h"
#include "../header/BaseCharacterState.h"
#include "../header/EntityController.h"

void OfficerMob::Init(OfficerInitData data, int setOfficerID)
{
	BaseOfficer::Init(data, setOfficerID);
	_groupType = CharacterGroup::ENTITY;
	SetImpossible(false);
	_officerType = OfficerType::MOB;
	layer = Layer::MIDDLE;
	pController = new EntityController(this);
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