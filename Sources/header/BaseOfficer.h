#pragma once
#include <DxLib.h>
#include "../header/BaseCharacter.h"
#include "../header/OfficerInitData.h"
#include "../header/BaseSuit.h"
#include "../header/BaseWeapon.h"

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
		_officerType = OfficerType::NONE;
		_officerID = -1;
		pCharacterState = NULL;
	}
	virtual ~BaseOfficer();

	virtual void Init(OfficerInitData data, int setOfficerID, Vector2 position);
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	void TakeDamage(int strength, Type damageType) override;
	void DecreaseMental(int decreaseValue);

	int GetOfficerID(){ return _officerID; }
	OfficerType GetOfficerType(){ return _officerType; }
	BaseSuit* GetSuit(){ return suit; }
	BaseWeapon* GetWeapon() { return weapon; }
	int GetMental(){ return _mental; }
	std::string GetName(){ return _officerName; }
	int* GetParameter() { return _parameter; }
	OfficerInitData GetOfficerInitData()
	{
		OfficerInitData data;
		data.name = _officerName;
		data.health = health;
		data.mental = _mental;
		data.suitID = _suitID;
		data.weaponID = _weaponID;
		data.type = _officerType;
		for (int i = 0; i < (int)Type::MAX; ++i)
		{
			data.param[i] = _parameter[i];
		}
		return data;
	}
	void SetOfficerID(int officerID){ _officerID = officerID; }
	void SetOfficerType(OfficerType type){ _officerType = type; }
	void SetSuit(BaseSuit* baseSuit){ suit = baseSuit; }
	void SetWeapon(BaseWeapon* baseWeapon){ weapon = baseWeapon; }
	void SetMental(int value) { _mental = value; }
	void SetName(std::string name){ _officerName = name; }
	void SetParameter(Type type, int value) { _parameter[(int)type] = value; }

protected:
	BaseSuit* suit;
	BaseWeapon* weapon;
	Type attackType;
	OfficerType _officerType;
	int _officerID;
	int _suitID;
	int _weaponID;
	int _mental;
	std::string _officerName;
	int _parameter[(int)Type::MAX];

private:
};