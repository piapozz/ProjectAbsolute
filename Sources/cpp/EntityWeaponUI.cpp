#include "../header/EntityWeaponUI.h"
#include "../header/ObjectFactory.h"

EntityWeaponUI::EntityWeaponUI(Transform setTransform, LayerSetting layerSetting)
{
	BaseUIScreen::Init(setTransform, layerSetting);
	_isLock = true;

	ObjectFactory& factory = ObjectFactory::Instance();
	Transform worldTransform = Transform(Vector2::zero(), Vector2::one(), this);
	LayerSetting layer = LayerSetting(true, false, Layer::MIDDLE);

	// äÓëb
	worldTransform = Transform(Vector2::zero(), Vector2::one(), this);
	_BGImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, false, layer);
	_BGImage->SetOutLineColor(GetColor(255, 128, 0));
	worldTransform = Transform(_INFORMATION_TEXT_POS, Vector2::one(), this);
	_informationText = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_informationText->SetText(_INFORMATION_TEXT);
	// ÉçÉbÉN
	worldTransform = Transform(_LOCK_IMAGE_POS, _LOCK_IMAGE_SCALE, this);
	_lockImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, false, layer);
	worldTransform = Transform(_LOCK_TEXT_POS, Vector2::one(), this);
	_lockText = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_lockText->SetText(_LOCK_TEXT);
	// âÊëú
	worldTransform = Transform(_IMAGE_POS, _IMAGE_SCALE, this);
	_image = factory.CreateWithArgs<UIScreenImage>(worldTransform, false, layer);
	// äÎåØìx
	worldTransform = Transform(_RANK_TEXT_POS, Vector2::one(), this);
	_rankText = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_rankText->SetText(_LOCK_TEXT);
}

void EntityWeaponUI::Draw()
{
	_BGImage->Draw();
	_informationText->Draw();
	if (_isLock)
	{
		_lockImage->Draw();
		_lockText->Draw();
	}
	else
	{
		_image->Draw();
		_rankText->Draw();

	}
}