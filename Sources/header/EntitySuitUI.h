#pragma once
#include "BaseObject.h"
#include "UIScreen.h"

class EntitySuitUI : public BaseObject
{
public:
	EntitySuitUI(Transform setTransform, LayerSetting layerSetting, std::string tipsText);
	~EntitySuitUI(){}

	void SetActive(bool active);
	inline void SetLock(bool isLock){ _isLock = isLock; }
	void Draw();

private:
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

