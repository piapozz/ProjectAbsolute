#pragma once
#include <DxLib.h>
#include "../header/BaseCharacter.h"
#include "../header/RouteSearcher.h"
#include "../header/StateArgs.h"

class BaseOfficerState;
class OfficerInitData;

/*
 * Sein
 * Officer‚ÌŠî’êƒNƒ‰ƒX
 */
class BaseOfficer : public BaseCharacter
{
public:
	BaseOfficer();
	virtual ~BaseOfficer();

	virtual void Init(OfficerInitData data, int setOfficerID);
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	int TakeDamege(int strength, Type damageType) override;

	void TowardsNotice();
	void ArriveNotice();
	void ChangeState(OfficerStateID stateID, StateArgs* args = nullptr);
	void ChangeMoveState(Vector2 targetPos, SecureRoom* secureRoom = nullptr);

	void SetPosition(Vector2 setPosition){ position = setPosition; }
	Vector2 GetPosition(){ return position; }
	Vector2 GetPastPosition(){ return _pastPosition; }
	void SetOfficerID(int officerID){ _officerID = officerID; }
	int GetOfficerID(){ return _officerID; }
	void SetOfficerType(OfficerType type){ _officerType = type; }
	OfficerType GetOfficerType(){ return _officerType; }
	void SetArmor(int armorID){ _armorID = armorID; }
	void SetWeapon(int weaponID){ _weaponID = weaponID; }
	int GetMental(){ return _mental; }
	void SetMental(int value) { _mental = value; }

	BaseOfficerState* pOfficerState;
	unsigned int color;

private:

protected:
	int _officerID;
	int _armorID;
	int _weaponID;
	int _mental;

	Vector2 _pastPosition;
	OfficerType _officerType;
};