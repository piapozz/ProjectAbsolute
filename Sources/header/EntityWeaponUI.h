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

	void Draw();
	void SetWeapon(Level setLevel, std::string setName, Type setType, int setDamage, int setSpeed, int setRange);
	inline void SetLock(bool isLock){ _isLock = isLock; }

private:
	UIScreenImage* _BGImage;
	UIScreenImage* _lockImage;
	UIScreenText* _lockText;
	UIScreenText* _informationText;
	UIScreenImage* _image;
	UIScreenText* _rank;
	UIScreenText* _name;
	UIScreenText* _typeInformation;
	UIScreenText* _type;
	UIScreenText* _damageInformation;
	UIScreenText* _damage;
	UIScreenText* _speedInformation;
	UIScreenText* _speed;
	UIScreenText* _rangeInformation;
	UIScreenText* _range;
	bool _isLock;

	const Vector2 _INFORMATION_TEXT_POS = Vector2(-0.5f, -0.95f);
	const std::string _INFORMATION_TEXT = "エンティティ 武器";
	const Vector2 _LOCK_TEXT_POS = Vector2(-0.8f, 0.0f);
	const std::string _LOCK_TEXT = "規定作業回数で解除";
	const Vector2 _LOCK_IMAGE_POS = Vector2(0.0f, 0.05f);
	const Vector2 _LOCK_IMAGE_SCALE = Vector2(0.95f, 0.9f);
	const Vector2 _IMAGE_POS = Vector2(0.0f, -0.5f);
	const Vector2 _IMAGE_SCALE = Vector2(0.95f, 0.3f);
	const Vector2 _RANK_TEXT_POS = Vector2(-0.1f, -0.15f);
	const Vector2 _NAME_TEXT_POS = Vector2(-0.1f, 0.0f);
	const Vector2 _TYPE_INFORMATION_TEXT_POS = Vector2(-0.5f, 0.15f);
	const std::string _TYPE_INFORMATION_TEXT = "属性";
	const Vector2 _TYPE_TEXT_POS = Vector2(0.5f, 0.15f);
	const Vector2 _DAMAGE_INFORMATION_TEXT_POS = Vector2(-0.5f, 0.3f);
	const std::string _DAMAGE_INFORMATION_TEXT = "ダメージ";
	const Vector2 _DAMAGE_TEXT_POS = Vector2(0.5f, 0.3f);
	const Vector2 _SPEED_INFORMATION_TEXT_POS = Vector2(-0.5f, 0.45f);
	const std::string _SPEED_INFORMATION_TEXT = "速度";
	const Vector2 _SPEED_TEXT_POS = Vector2(0.5f, 0.45f);
	const Vector2 _RANGE_INFORMATION_TEXT_POS = Vector2(-0.5f, 0.6f);
	const std::string _RANGE_INFORMATION_TEXT = "射程";
	const Vector2 _RANGE_TEXT_POS = Vector2(0.5f, 0.6f);
};

