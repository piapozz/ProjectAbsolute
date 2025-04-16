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

	virtual void Init();
	void Proc() override;
	void Draw() override;
	void Teardown() override;

	void ChangeState(BaseOfficerState* officerState);

	void SetOfficerID(int officerID){ _officerID = officerID; }
	int GetOfficerID(){ return _officerID; }
	void SetOfficerType(OfficerType type){ _officerType = type; }
	OfficerType GetOfficerType(){ return _officerType; }
	void SetArmor(int armorID){ _armorID = armorID; }
	void SetWeapon(int weaponID){ _weaponID = weaponID; }

	VECTOR position;
	BaseOfficerState* pOfficerState;

private:

protected:
	int _officerID;
	int _armorID;
	int _weaponID;

	OfficerType _officerType;
};