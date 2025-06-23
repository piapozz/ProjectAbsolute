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
	LayerSetting layer = LayerSetting(true, false, Layer::MIDDLE);

	Transform worldTransform = Transform(Vector2().zero(), Vector2().one(), this);
	_BGImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, true, layer);
	worldTransform = Transform(_INFORMATION_TEXT_POS, Vector2().one(), this);
	_informationText = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_informationText->SetText(_INFORMATION_TEXT);
	worldTransform = Transform(_INFORMATION_POS, _INFORMATION_SCALE, this);
	_entityInformation = factory.CreateWithArgs<EntityInformationUI>(worldTransform, layer);
	worldTransform = Transform(_OPERATION_POS, _OPERATION_SCALE, this);
	_entityOperation = factory.CreateWithArgs<EntityOperationUI>(worldTransform, layer);
	worldTransform = Transform(_MANAGEMENT_POS, _MANAGEMENT_SCALE, this);
	_entityManagement = factory.CreateWithArgs<EntityManagementUI>(worldTransform, layer);
	worldTransform = Transform(_ESCAPE_POS, _ESCAPE_SCALE, this);
	_entityEscape = factory.CreateWithArgs<EntityEscapeUI>(worldTransform, layer);
	worldTransform = Transform(_WEAPON_POS, _WEAPON_SCALE, this);
	_entityWeapon = factory.CreateWithArgs<EntityWeaponUI>(worldTransform, layer);
	worldTransform = Transform(_SUIT_POS, _SUIT_SCALE, this);
	_entitySuit = factory.CreateWithArgs<EntitySuitUI>(worldTransform, layer);
	worldTransform = Transform(_OPERATION_COUNT_TEXT_POS, Vector2().one(), this);
	_operationCountText = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_operationCountText->SetText(_OPERATION_COUNT_TEXT);
	worldTransform = Transform(_EXIT_BUTTON_POS, _EXIT_BUTTON_SCALE, this);
	layer = LayerSetting(true, true, Layer::MIDDLE);
	_exitButton = factory.CreateWithArgs<UIScreenButton>(worldTransform, true, layer);
	_exitButton->SetCallback([this]() { this->SetActive(false); });
	_exitButton->SetText(_EXIT_BUTTON_TEXT);
}

void UIEntity::Proc()
{
	_BGImage->Proc();
	_informationText->Proc();
	_entityInformation->Proc();
	_entityOperation->Proc();
	_entityManagement->Proc();
	_entityEscape->Proc();
	_entityWeapon->Proc();
	_entitySuit->Proc();
	_operationCountText->Proc();
	_exitButton->Proc();
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