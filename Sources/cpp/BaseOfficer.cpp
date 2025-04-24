#include "../header/BaseOfficer.h"
#include "../header/CharacterStateFactory.h"
#include "../header/OfficerInitData.h"
#include "../header/StageManager.h"

BaseOfficer::BaseOfficer()
{
	_officerType = OfficerType::NONE;
	_officerID = -1;
	pCharacterState = NULL;
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

	SetImpossible(true);

	SetOfficerID(setOfficerID);
	ChangeState(OfficerStateID::OFFICER_IDLE, nullptr);
}

void BaseOfficer::Proc()
{
	BaseObject::Proc();

	if (health <= 0) ChangeState(OfficerStateID::OFFICER_DEAD, nullptr);
	if (_mental <= 0) ChangeState(OfficerStateID::OFFICER_PANIC, nullptr);

	pCharacterState->Update(this);
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