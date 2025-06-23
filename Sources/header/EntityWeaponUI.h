#pragma once
#include "BaseUIScreen.h"
#include "UIScreen.h"

class EntityWeaponUI : public BaseUIScreen
{
public:
	static std::string StaticTypeName() {
		return "EntityWeaponUI";
	}

	EntityWeaponUI(){}
	EntityWeaponUI(Transform setTransform, LayerSetting layerSetting);
	~EntityWeaponUI(){}

	void SetActive(bool active);
	inline void SetLock(bool isLock){ _isLock = isLock; }
	void Draw();

private:
	UIScreenImage* _BGImage;
	UIScreenText* _lockText;
	UIScreenText* _information;
	UIScreenImage* _image;
	UIScreenText* _rank;
	UIScreenText* _name;
	UIScreenText* _typeInformtaion;
	UIScreenText* _type;
	UIScreenText* _damageInformation;
	UIScreenText* _damage;
	UIScreenText* _speedInformation;
	UIScreenText* _speed;
	UIScreenText* _rangeInformation;
	UIScreenText* _range;

	bool _isLock;
	const std::string _LOCK_TEXT = "ÉçÉbÉNíÜ";
	const std::string _TIPS_INFORMATION = "ä«óùï˚ñ@%d";
};

