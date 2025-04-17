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
	ChangeState(OfficerStateID::OFFICER_IDLE, nullptr);
}

void BaseOfficer::Proc()
{
	BaseObject::Proc();

	if (health <= 0) ChangeState(OfficerStateID::OFFICER_DEAD, nullptr);
	if (mental <= 0) ChangeState(OfficerStateID::OFFICER_PANIC, nullptr);

	pOfficerState->Update(this);
}

void BaseOfficer::Draw()
{
	BaseObject::Draw();
}

void BaseOfficer::Teardown()
{
	BaseObject::Teardown();
}

int BaseOfficer::TakeDamege(int strength, Type damageType)
{
	float index;
	index = strength * defenseRatio[(int)damageType];
	return ceil(index);
}

void BaseOfficer::ChangeState(OfficerStateID stateID, StateArgs* args)
{
	if (pOfficerState)
	{
		pOfficerState->Exit(this);
		delete pOfficerState;
	}

	pOfficerState = OfficerStateFactory::CreateState(stateID ,args);

	if (pOfficerState)
	{
		pOfficerState->Enter(this);
	}
}