#include "../header/OfficerMob.h"
#include "../header/BaseCharacterState.h"
#include "../header/OfficerController.h"

void OfficerMob::Init(OfficerInitData data, int setOfficerID, Vector2 position)
{
	BaseOfficer::Init(data, setOfficerID,position);
	_groupType = CharacterGroup::ENTITY;
	SetImpossible(false);
	_officerType = OfficerType::MOB;
	layer = Layer::MIDDLE;
	// pController = new OfficerController(this);
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