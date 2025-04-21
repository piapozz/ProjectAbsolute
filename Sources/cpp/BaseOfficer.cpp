#include "../header/BaseOfficer.h"
#include "../header/OfficerStateFactory.h"
#include "../header/OfficerInitData.h"

BaseOfficer::BaseOfficer()
{
	_officerType = OfficerType::NONE;
	_officerID = -1;
	pOfficerState = NULL;
}

BaseOfficer::~BaseOfficer()
{

}

void BaseOfficer::Init(OfficerInitData data, int setOfficerID)
{
	health = data.health;
	mental = data.mental;
	_armorID = data.armorID;
	_weaponID = data.weaponID;

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

	VECTOR spherePosition;
	spherePosition.x = position.x;
	spherePosition.y = position.y;
	spherePosition.z = 0;
	DrawSphere3D(spherePosition, 10, 32, color, GetColor(0, 0, 0), TRUE);
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