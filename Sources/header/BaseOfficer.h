#pragma once
#include "../header/BaseCharacter.h"
#include "../header/BaseOfficerState.h"

/*
 * Sein
 * Officer‚ÌŠî’êƒNƒ‰ƒX
 */
class BaseOfficer : BaseCharacter
{
public:
	void SetOfficerID(int officerID){ _officerID = officerID; }
	int GetOfficerID(){ return _officerID; }
	void SetArmor(int armorID){ _armorID = armorID; }
	void SetWeapon(int weaponID){ _weaponID = weaponID; }

private:
	BaseOfficer();
	~BaseOfficer();

	virtual void Init();
	virtual void Proc();
	virtual void Teardown();

	int _officerID;
	int _armorID;
	int _weaponID;

	BaseOfficerState* _pOfficerState;
};