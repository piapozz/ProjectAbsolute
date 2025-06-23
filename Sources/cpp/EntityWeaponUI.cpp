#include "../header/EntityWeaponUI.h"
#include "../header/ObjectFactory.h"

EntityWeaponUI::EntityWeaponUI(Transform setTransform, LayerSetting layerSetting)
{
	BaseUIScreen::Init(setTransform, layerSetting);

	ObjectFactory& factory = ObjectFactory::Instance();
	LayerSetting layer = LayerSetting(true, false, Layer::MIDDLE);

	Transform worldTransform = Transform(Vector2::zero(), Vector2::one(), this);
	_BGImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, true, layer);
}

void EntityWeaponUI::SetActive(bool active)
{
	_BGImage->SetActive(active);
	//_lockText->SetActive(active);
	//_information->SetActive(active);
	//_image->SetActive(active);
	//_rank->SetActive(active);
	//_name->SetActive(active);
	//_typeInformtaion->SetActive(active);
	//_type->SetActive(active);
	//_damageInformation->SetActive(active);
	//_damage->SetActive(active);
	//_speedInformation->SetActive(active);
	//_speed->SetActive(active);
	//_rangeInformation->SetActive(active);
	//_range->SetActive(active);
}

void EntityWeaponUI::Draw()
{
	_BGImage->Draw();
	//_lockText->Draw();
	//_information->Draw();
	//_image->Draw();
	//_rank->Draw();
	//_name->Draw();
	//_typeInformtaion->Draw();
	//_type->Draw();
	//_damageInformation->Draw();
	//_damage->Draw();
	//_speedInformation->Draw();
	//_speed->Draw();
	//_rangeInformation->Draw();
	//_range->Draw();
}