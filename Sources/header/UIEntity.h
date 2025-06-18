#pragma once
#include "BaseObject.h"

class EntityInformationUI;
class EntityManagementUI;
class EntityManagementTipsUI;
class EntityEscapeUI;
class EntityWeaponUI;
class EntitySuitUI;
class UIScreenImage;
class UIScreenText;

class UIEntity: public BaseUIScreen
{
public:
	UIEntity();
	~UIEntity(){}

	void Proc() override;
	void Draw() override;

	static std::string StaticTypeName() {
		return "UIEntity";
	}

private:
	UIScreenImage* _BGImage;
	UIScreenText* _informationText;
	EntityInformationUI* _entityInformation;
	EntityManagementUI* _entityManagement;
	EntityEscapeUI* _entityEscape;
	EntityWeaponUI* _entityWeapon;
	EntitySuitUI* _entitySuit;

	const Vector2 _WINDOW_SCALE = Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);
	const Vector2 _CENTER_POS = _WINDOW_SCALE / 2;
	const Transform _TRANSFORM = Transform(_CENTER_POS, _WINDOW_SCALE);
	const LayerSetting _DEFAULT_LAYER = LayerSetting(false, false, Layer::MIDDLE);
	const Vector2 _INFORMTION_POS = Vector2(-0.3f, 0.2f);
	const Vector2 _INFORMTION_SCALE = Vector2(0.2f, 0.7f);
	const Vector2 _MANAGEMENT_POS = Vector2(0.2f, -0.4f);
	const Vector2 _MANAGEMENT_SCALE = Vector2(0.3f, 0.4f);
	const Vector2 _ESCAPE_POS = Vector2(0.7f, -0.7f);
	const Vector2 _ESCAPE_SCALE = Vector2(0.3f, 0.2f);
};

