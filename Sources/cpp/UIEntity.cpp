#include "../header/UIScreen.h"
#include "../header/UIEntity.h"
#include "../header/EntityInformationUI.h"
#include "../header/EntityOperationUI.h"
#include "../header/EntityManagementUI.h"
#include "../header/EntityEscapeUI.h"
#include "../header/EntityWeaponUI.h"
#include "../header/EntitySuitUI.h"
#include "../header/ObjectFactory.h"

UIEntity::UIEntity()
{
	Init();
}

void UIEntity::Init()
{
	BaseUIScreen::Init(_TRANSFORM, _DEFAULT_LAYER);
	ObjectFactory& factory = ObjectFactory::Instance();
	Vector2 position = transform.position;
	Vector2 scale = transform.scale;
	Transform worldTransform = Transform();
	LayerSetting layer = LayerSetting(true, false, Layer::MIDDLE);
	
	// 基礎
	worldTransform = Transform(Vector2().zero(), Vector2().one(), this);
	_BGImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, true, layer);
	_BGImage->SetColor(COLOR_BLACK);
	worldTransform = Transform(_INFORMATION_TEXT_POS, Vector2().one(), this);
	_informationText = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_informationText->SetText(_INFORMATION_TEXT);
	// 基本情報
	worldTransform = Transform(_INFORMATION_POS, _INFORMATION_SCALE, this);
	_entityInformation = factory.CreateWithArgs<EntityInformationUI>(worldTransform, layer);
	// 作業好感度
	worldTransform = Transform(_OPERATION_POS, _OPERATION_SCALE, this);
	_entityOperation = factory.CreateWithArgs<EntityOperationUI>(worldTransform, layer);
	// 管理方法
	worldTransform = Transform(_MANAGEMENT_POS, _MANAGEMENT_SCALE, this);
	_entityManagement = factory.CreateWithArgs<EntityManagementUI>(worldTransform, layer, 5);
	// 脱走情報
	float defence[(int)Type::MAX] = {0.7f, 1.2f, 0.3f, 1.5f};
	worldTransform = Transform(_ESCAPE_POS, _ESCAPE_SCALE, this);
	_entityEscape = factory.CreateWithArgs<EntityEscapeUI>(worldTransform, layer, defence);
	// 武器防具情報
	worldTransform = Transform(_WEAPON_POS, _WEAPON_SCALE, this);
	_entityWeapon = factory.CreateWithArgs<EntityWeaponUI>(worldTransform, layer);
	worldTransform = Transform(_SUIT_POS, _SUIT_SCALE, this);
	_entitySuit = factory.CreateWithArgs<EntitySuitUI>(worldTransform, layer);
	// 作業回数
	worldTransform = Transform(_OPERATION_COUNT_TEXT_POS, Vector2().one(), this);
	_operationCountText = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_operationCountText->SetText(_OPERATION_COUNT_TEXT);
	// 戻るボタン
	worldTransform = Transform(_EXIT_BUTTON_POS, _EXIT_BUTTON_SCALE, this);
	layer = LayerSetting(true, true, Layer::MIDDLE);
	_exitButton = factory.CreateWithArgs<UIScreenButton>(worldTransform, true, layer);
	_exitButton->SetCallback([this]() { this->SetActive(false); });
	_exitButton->SetText(_EXIT_BUTTON_TEXT);
}

void UIEntity::Draw()
{
	_BGImage->Draw();
	_informationText->Draw();
	_entityInformation->Draw();
	_entityOperation->Draw();
	_entityManagement->Draw();
	_entityEscape->Draw();
	_entityWeapon->Draw();
	_entitySuit->Draw();
	_operationCountText->Draw();
	_exitButton->Draw();
}