#include "../header/BaseOfficer.h"
#include "../header/OfficerStateFactory.h"

BaseOfficer::BaseOfficer()
{
	pOfficerState = NULL;
	_officerType = OfficerType::NONE;
	_officerID = NULL;
	_armorID = NULL;
	_weaponID = NULL;
}

BaseOfficer::~BaseOfficer()
{

}

void BaseOfficer::Init(Vector2 setPosition, int setOfficerID)
{
	position = setPosition;
	SetOfficerID(setOfficerID);
	ChangeState(OfficerStateID::OFFICER_IDLE);
}

void BaseOfficer::Proc()
{
	BaseObject::Proc();
}

void BaseOfficer::Draw()
{
	BaseObject::Draw();
}

void BaseOfficer::Teardown()
{
	BaseObject::Teardown();
}

void BaseOfficer::ChangeState(OfficerStateID stateID)
{
	if (pOfficerState)
	{
		pOfficerState->Exit(this);
		delete pOfficerState;
	}

	pOfficerState = OfficerStateFactory::CreateState(stateID);

	if (pOfficerState)
	{
		pOfficerState->Enter(this);
	}
}