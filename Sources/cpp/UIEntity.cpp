#include "../header/UIScreen.h"
#include "../header/UIEntity.h"
#include "../header/EntityInformationUI.h"
#include "../header/EntityManagementUI.h"
#include "../header/EntityEscapeUI.h"
#include "../header/EntityWeaponUI.h"
#include "../header/EntitySuitUI.h"
#include "../header/ObjectFactory.h"

UIEntity::UIEntity()
{
	BaseUIScreen::Init(_TRANSFORM, _DEFAULT_LAYER);
	objectType = ObjectType::SCREEN_UI;
	ObjectFactory& factory = ObjectFactory::Instance();
	Vector2 position = transform.position;
	Vector2 scale = transform.scale;
	LayerSetting layer = LayerSetting(true, false, Layer::MIDDLE);
	
	Transform worldTransform = Transform(Vector2().zero(), Vector2().one(), this);
	_BGImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, true, layer);
	worldTransform = Transform(Vector2(-0.9f, -0.9f), Vector2(0.4f, 0.2f), this);
	_informationText = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_informationText->SetText("Entity Information");
	/*Transform informationTrans = Transform(_INFORMTION_POS, _INFORMTION_SCALE, this);
	LayerSetting informationLayer = LayerSetting(false, false, Layer::MIDDLE);
	_entityInformation = factory.CreateWithArgs<EntityInformationUI>(informationTrans, informationLayer);*/
}

void UIEntity::Proc()
{
	_BGImage->Proc();
	_informationText->Proc();
	/*_entityInformation->Proc();
	_entityManagement->Proc();
	_entityEscape->Proc();
	_entityWeapon->Proc();
	_entitySuit->Proc();*/
}

void UIEntity::Draw()
{
	_BGImage->Draw();
	_informationText->Draw();
	/*_entityInformation->Draw();
	_entityManagement->Draw();
	_entityEscape->Draw();
	_entityWeapon->Draw();
	_entitySuit->Draw();*/
}