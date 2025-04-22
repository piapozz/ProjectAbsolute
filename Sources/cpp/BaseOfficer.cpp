#include "../header/BaseOfficer.h"
#include "../header/OfficerStateFactory.h"
#include "../header/OfficerInitData.h"
#include "../header/StageManager.h"

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
	BaseCharacter::Init();
	position = data.position;
	_pastPosition = position;
	health = data.health;
	maxHealth = health;
	_mental = data.mental;
	_armorID = data.armorID;
	_weaponID = data.weaponID;

	SetOfficerID(setOfficerID);
	ChangeState(OfficerStateID::OFFICER_IDLE, nullptr);
}

void BaseOfficer::Proc()
{
	BaseObject::Proc();

	if (health <= 0) ChangeState(OfficerStateID::OFFICER_DEAD, nullptr);
	if (_mental <= 0) ChangeState(OfficerStateID::OFFICER_PANIC, nullptr);

	pOfficerState->Update(this);
}

void BaseOfficer::Draw()
{
	BaseObject::Draw();

	int temp = 0 * 360 / 100;
	float radian = (float)temp * DX_PI / 180.0f;
	float x = cosf(radian) * 10;
	float y = sinf(radian) * 10;
	VECTOR Pos1 = VGet(position.x + x, position.y + y, 0);

	for (int i = 1 ; i < 100;i++)
	{
		temp = i * 360 / 100;
		radian = (float)temp * DX_PI / 180.0f;
		x = cosf(radian) * 10;
		y = sinf(radian) * 10;
		VECTOR Pos2 = VGet(position.x + x, position.y + y, 0);
		DrawLine3D(Pos1, Pos2, color) ;
		Pos1 = Pos2;
	}
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

void BaseOfficer::TowardsNotice()
{

}

void BaseOfficer::ArriveNotice()
{

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

void BaseOfficer::ChangeMoveState(Vector2 targetPos, SecureRoom* secureRoom)
{
	std::vector<Vector2> routeList;
	routeList = StageManager::FindPath(position, targetPos);
	StateArgs* args = new StateArgs();
	args->targetPosList = routeList;
	if (secureRoom != nullptr)
	{
		args->secureRoom = secureRoom;
		ChangeState(OfficerStateID::OFFICER_OPERATION_MOVE, args);
		_pastPosition = routeList[0];
		return;
	}
	ChangeState(OfficerStateID::OFFICER_MOVE, args);
	// ‰ß‹Ž‚ÌˆÊ’u‚ð•Û‘¶
	_pastPosition = routeList[0];
}