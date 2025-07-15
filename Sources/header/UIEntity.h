#pragma once
#include "BaseObject.h"

class EntityInformationUI;
class EntityOperationUI;
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
	static std::string StaticTypeName() {
		return "UIEntity";
	}

	UIEntity();
	~UIEntity(){}

	void Init();
	void Draw() override;
	void SetEntityData(int setID);
	void SetActive(bool setActive) override;

private:
	UIScreenImage* _BGImage;
	UIScreenText* _informationText;
	EntityInformationUI* _entityInformation;
	EntityOperationUI* _entityOperation;
	EntityManagementUI* _entityManagement;
	EntityEscapeUI* _entityEscape;
	EntityWeaponUI* _entityWeapon;
	EntitySuitUI* _entitySuit;
	UIScreenText* _operationCountText;
	UIScreenButton* _exitButton;

	const Vector2 _WINDOW_SCALE = Vector2(WINDOW_WIDTH, WINDOW_HEIGHT);
	const Vector2 _CENTER_POS = _WINDOW_SCALE / 2;
	const Transform _TRANSFORM = Transform(_CENTER_POS, _WINDOW_SCALE);
	const LayerSetting _DEFAULT_LAYER = LayerSetting(false, false, Layer::MIDDLE);
	const Vector2 _BG_SCALE = Vector2(1.0f, 1.0f);
	const Vector2 _INFORMATION_TEXT_POS = Vector2(0.0f, -1.0f);
	const std::string _INFORMATION_TEXT = "エンティティ 情報";
	// 基本情報
	const Vector2 _INFORMATION_POS = Vector2(-0.65f, -0.4f);
	const Vector2 _INFORMATION_SCALE = Vector2(0.3f, 0.5f);
	// 作業情報
	const Vector2 _OPERATION_POS = Vector2(-0.65f, 0.5f);
	const Vector2 _OPERATION_SCALE = Vector2(0.3f, 0.4f);
	// 管理方法
	const Vector2 _MANAGEMENT_POS = Vector2(0, 0);
	const Vector2 _MANAGEMENT_SCALE = Vector2(0.3f, 0.9f);
	// 脱走情報
	const Vector2 _ESCAPE_POS = Vector2(0.65f, -0.6f);
	const Vector2 _ESCAPE_SCALE = Vector2(0.3f, 0.3f);
	// 武器情報
	const Vector2 _WEAPON_POS = Vector2(0.5f, 0.25f);
	const Vector2 _WEAPON_SCALE = Vector2(0.15f, 0.5f);
	// 防具情報
	const Vector2 _SUIT_POS = Vector2(0.8f, 0.25f);
	const Vector2 _SUIT_SCALE = Vector2(0.15f, 0.5f);
	// 作業回数
	const Vector2 _OPERATION_COUNT_TEXT_POS = Vector2(0.6f, 0.85f);
	const std::string _OPERATION_COUNT_TEXT = "作業回数 : ";
	// 戻る
	const Vector2 _EXIT_BUTTON_POS = Vector2(0.9f, 0.9f);
	const Vector2 _EXIT_BUTTON_SCALE = Vector2(0.1f, 0.1f);
	const std::string _EXIT_BUTTON_TEXT = "戻る";
	// フォントサイズ
	const int _INFORMATION_FONT_SIZE = 50;
	const int _MAIN_ITEM_FONT_SIZE = 30;
	const int _SUB_ITEM_FONT_SIZE = 20;

	void SetFontSize();
};

