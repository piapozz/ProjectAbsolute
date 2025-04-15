#pragma once
#include "../header/BaseCharacter.h"


/*
 * Sein
 * Officer‚ÌŠî’êƒNƒ‰ƒX
 */
class BaseOfficer : BaseCharacter
{
public:

	int GetOfficerID(){ return _officerID; }

private:
	BaseOfficer();
	~BaseOfficer();

	//void Init() override;
	//void Proc() override;
	//void Teardown() override;

	virtual void Init();
	virtual void Proc();
	virtual void Teardown();

	int _officerID;
	int _armorID;
	int _weaponID;
};