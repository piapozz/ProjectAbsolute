#include "../header/BaseOfficer.h"
#include "../header/CharacterStateFactory.h"
#include "../header/OfficerInitData.h"
#include "../header/StageManager.h"
#include "../header/ObjectManager.h"

#include "../header/SuitTriangle.h"
#include "../header/WeaponTriangle.h"

BaseOfficer::BaseOfficer()
{
	
}

BaseOfficer::~BaseOfficer()
{

}

void BaseOfficer::Init(OfficerInitData data, int setOfficerID, Vector2 position)
{
	SetPosition(position);
	Transform transformWorld = transform.GetWorldTransform();
	Vector2 transformPosition = transformWorld.position;
	ObjectManager& objectManager = ObjectManager::Instance();

	pastRoom = static_cast<BaseSection*>(objectManager.Instance().FindPosObject(transformPosition, ObjectType::SECTION));
	health = data.health;
	maxHealth = health;
	_maxMental = data.mental;

	_officerName = data.name;
	_mental = data.mental;
	_suitID = data.suitID;
	_weaponID = data.weaponID;
	for (int i = 0;i < (int)Type::MAX;i++)
	{
		_parameter[i] = data.param[i];
	}

	suit = new SuitTriangle();
	weapon = new WeaponTriangle();

	float* multipliers = suit->GetMultipliers();
	for (int i = 0;i < (int)Type::MAX;i++)
	{
		defenseRatio[i] = multipliers[i];
	}
	strength = weapon->GetDamage();
	attackType = weapon->GetDamageType();

	_attackStatus.attack = strength;
	_attackStatus.damageType = attackType;

	SetImpossible(true);

	SetOfficerID(setOfficerID);
	ChangeState(CharacterStateID::IDLE, nullptr);
}

void BaseOfficer::Proc()
{
	BaseObject::Proc();

	// pCharacterState->Update(this);
	// pController->UpdateAI();
}

void BaseOfficer::Draw()
{
	BaseObject::Draw();

	int temp = 0 * 360 / 100;
	float radian = (float)temp * DX_PI / 180.0f;
	Transform transformWorld = transform.GetWorldTransform();
	Vector2 position = transformWorld.position;
	Vector2 scale = transformWorld.scale;
	float x = cosf(radian) * (scale.y / 2);
	float y = sinf(radian) * (scale.y / 2);
	VECTOR Pos1 = VGet(position.x + x, (position.y + (scale.y / 2)) + y, 0);

	for (int i = 1 ; i < 100;i++)
	{
		temp = i * 360 / 100;
		radian = (float)temp * DX_PI / 180.0f;
		x = cosf(radian) * (scale.y / 2);
		y = sinf(radian) * (scale.y / 2);
		VECTOR Pos2 = VGet(position.x + x, (position.y + (scale.y / 2)) + y, 0);
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
			float paleDamage = maxHealth * (damage / 100.0f);
			DecreaseHealth(ceil(paleDamage));
			break;
	}
}

void BaseOfficer::DecreaseMental(int decreaseValue)
{
	_mental -= decreaseValue;
}
