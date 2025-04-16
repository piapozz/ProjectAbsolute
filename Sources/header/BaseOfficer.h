#pragma once
#include "../header/BaseCharacter.h"
#include "../header/BaseOfficerState.h"

/*
 * Sein
 * Officer‚ÌŠî’êƒNƒ‰ƒX
 */
class BaseOfficer : public BaseCharacter
{
public:
	BaseOfficer();
	virtual ~BaseOfficer();

	virtual void Init(Vector2 setPosition, int setOfficerID);
	void Proc() override;
	void Draw() override;
	void Teardown() override;

	void ChangeState(OfficerStateID stateID);

	void SetOfficerID(int officerID){ _officerID = officerID; }
	int GetOfficerID(){ return _officerID; }
	void SetOfficerType(OfficerType type){ _officerType = type; }
	OfficerType GetOfficerType(){ return _officerType; }
	void SetArmor(int armorID){ _armorID = armorID; }
	void SetWeapon(int weaponID){ _weaponID = weaponID; }

	BaseOfficerState* pOfficerState;

private:

protected:
	int _officerID;
	int _armorID;
	int _weaponID;

	OfficerType _officerType;
};