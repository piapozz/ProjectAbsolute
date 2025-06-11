#include "../header/BaseOfficer.h"
#include "../header/CharacterStateFactory.h"
#include "../header/OfficerInitData.h"
#include "../header/StageManager.h"
#include "../header/ObjectManager.h"

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
	position = data.position;
	ObjectManager& objectManager = ObjectManager::Instance();

	pastRoom = static_cast<BaseSection*>(objectManager.Instance().FindPosObject(position, ObjectType::SECTION));
	health = data.health;
	maxHealth = health;
	_mental = data.mental;
	_armorID = data.armorID;
	_weaponID = data.weaponID;

	SetImpossible(true);

	SetOfficerID(setOfficerID);
	ChangeState(CharacterStateID::IDLE, nullptr);
}

void BaseOfficer::Proc()
{
	BaseObject::Proc();

	pCharacterState->Update(this);
}

void BaseOfficer::Draw()
{
	BaseObject::Draw();

	int temp = 0 * 360 / 100;
	float radian = (float)temp * DX_PI / 180.0f;
	float x = cosf(radian) * (objectSize.y / 2);
	float y = sinf(radian) * (objectSize.y / 2);
	VECTOR Pos1 = VGet(position.x + x, (position.y + (objectSize.y / 2)) + y, 0);

	for (int i = 1 ; i < 100;i++)
	{
		temp = i * 360 / 100;
		radian = (float)temp * DX_PI / 180.0f;
		x = cosf(radian) * (objectSize.y / 2);
		y = sinf(radian) * (objectSize.y / 2);
		VECTOR Pos2 = VGet(position.x + x, (position.y + (objectSize.y / 2)) + y, 0);
		DrawLine3D(Pos1, Pos2, color) ;
		Pos1 = Pos2;
	}
}

void BaseOfficer::Teardown()
{
	BaseObject::Teardown();
}

void BaseOfficer::TakeDamage(int strength, Type damageType)
{
	float index;
	index = strength * defenseRatio[(int)damageType];
	int damage = ceil(index);

	switch (damageType)
	{
		case Type::RED:
			DecreaseHealth(damage);
			break;
		case Type::WHITE:
			DecreaseMental(damage);
			break;
		case Type::BLACK:
			DecreaseHealth(damage);
			DecreaseMental(damage);
			break;
		case Type::PALE:
			int paleDamage = health * (damage / 100);
			DecreaseHealth(ceil(paleDamage));
			break;
	}
}

void BaseOfficer::DecreaseMental(int decreaseValue)
{
	_mental -= decreaseValue;
}
