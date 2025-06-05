#pragma once
#include <DxLib.h>
#include "../header/BaseCharacter.h"
#include "../header/OfficerInitData.h"

/*
 * Sein
 * Officer‚ÌŠî’êƒNƒ‰ƒX
 */
class BaseOfficer : public BaseCharacter
{
public:
	BaseOfficer();
	BaseOfficer(LayerSetting layerSetting)
		: BaseCharacter(layerSetting) {
	}
	virtual ~BaseOfficer();

	virtual void Init(OfficerInitData data, int setOfficerID);
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	void TakeDamage(int strength, Type damageType) override;
	void DecreaseMental(int decreaseValue);

	void SetOfficerID(int officerID){ _officerID = officerID; }
	int GetOfficerID(){ return _officerID; }
	void SetOfficerType(OfficerType type){ _officerType = type; }
	OfficerType GetOfficerType(){ return _officerType; }
	void SetArmor(int armorID){ _armorID = armorID; }
	void SetWeapon(int weaponID){ _weaponID = weaponID; }
	int GetMental(){ return _mental; }
	void SetMental(int value) { _mental = value; }

private:

protected:
	int _officerID;
	int _armorID;
	int _weaponID;
	int _mental;

	OfficerType _officerType;
};