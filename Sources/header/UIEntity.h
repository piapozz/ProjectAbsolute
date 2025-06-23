#pragma once
#include "BaseObject.h"

class EntityInformationUI;
class EntityOperationFavorUI;
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
	EntityOperationFavorUI* _entityOperationFavor;
	EntityManagementUI* _entityManagement;
	EntityEscapeUI* _entityEscape;
	EntityWeaponUI* _entityWeapon;
	EntitySuitUI* _entitySuit;

	const Vector2 _WINDOW_SCALE = Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);
	const Vector2 _CENTER_POS = _WINDOW_SCALE / 2;
	const Transform _TRANSFORM = Transform(_CENTER_POS, _WINDOW_SCALE);
	const LayerSetting _DEFAULT_LAYER = LayerSetting(false, false, Layer::MIDDLE);
	const Vector2 _INFORMATION_POS = Vector2(-0.65f, -0.4f);
	const Vector2 _INFORMATION_SCALE = Vector2(0.3f, 0.5f);
	const Vector2 _OPERATION_POS = Vector2(-0.65f, 0.55f);
	const Vector2 _OPERATION_SCALE = Vector2(0.3f, 0.35f);
	const Vector2 _MANAGEMENT_POS = Vector2(0, 0);
	const Vector2 _MANAGEMENT_SCALE = Vector2(0.3f, 0.9f);
	const Vector2 _ESCAPE_POS = Vector2(0.65f, -0.65f);
	const Vector2 _ESCAPE_SCALE = Vector2(0.3f, 0.25f);
	const Vector2 _WEAPON_POS = Vector2(0.485f, 0.1f);
	const Vector2 _WEAPON_SCALE = Vector2(0.14f, 0.45f);
	const Vector2 _SUIT_POS = Vector2(0.85f, 0.1f);
	const Vector2 _SUIT_SCALE = Vector2(0.14f, 0.45f);
};

