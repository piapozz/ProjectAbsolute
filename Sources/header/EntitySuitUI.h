#pragma once
#include "BaseUIScreen.h"
#include "UIScreen.h"

class EntitySuitUI : public BaseUIScreen
{
public:
	static std::string StaticTypeName() {
		return "EntitySuitUI";
	}

	EntitySuitUI(){
	}
	EntitySuitUI(Transform setTransform, LayerSetting layerSetting);
	~EntitySuitUI(){
	}

	void Draw();
	inline void SetLock(bool isLock){
		_isLock = isLock;
	}

private:
	UIScreenImage* _BGImage;
	UIScreenImage* _lockImage;
	UIScreenText* _lockText;
	UIScreenText* _informationText;
	UIScreenImage* _image;
	UIScreenText* _rankText;
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

	const Vector2 _INFORMATION_TEXT_POS = Vector2(-0.5f, -0.95f);
	const std::string _INFORMATION_TEXT = "エンティティ 防具";
	const Vector2 _LOCK_TEXT_POS = Vector2(-0.8f, 0.0f);
	const std::string _LOCK_TEXT = "規定作業回数で解除";
	const Vector2 _LOCK_IMAGE_POS = Vector2(0.0f, 0.05f);
	const Vector2 _LOCK_IMAGE_SCALE = Vector2(0.95f, 0.9f);
	const Vector2 _IMAGE_POS = Vector2(0.0f, -0.7f);
	const Vector2 _IMAGE_SCALE = Vector2(0.95f, 0.3f);
	const Vector2 _RANK_TEXT_POS = Vector2(-0.3f, -0.3f);
};

