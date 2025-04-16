#include "../header/BaseOfficer.h"

BaseOfficer::BaseOfficer()
{
	_pOfficerState = NULL;
	_officerType = OfficerType::NONE;
	_officerID = NULL;
	_armorID = NULL;
	_weaponID = NULL;
}

BaseOfficer::~BaseOfficer()
{

}

void BaseOfficer::Init()
{

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

void BaseOfficer::ChangeState(BaseOfficerState* officerState)
{
	pOfficerState = officerState;
}