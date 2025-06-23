#pragma once
#include "BaseUIScreen.h"
#include "UIScreen.h"

class EntitySuitUI : public BaseUIScreen
{
public:
	EntitySuitUI(){}
	EntitySuitUI(Transform setTransform, LayerSetting layerSetting);
	~EntitySuitUI(){}

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

