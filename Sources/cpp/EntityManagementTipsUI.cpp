#include "../header/ObjectFactory.h"
#include "../header/EntityManagementTipsUI.h"
#include "../header/UIScreen.h"

EntityManagementTipsUI::EntityManagementTipsUI(Transform setTransform, LayerSetting layerSetting, std::string tipsText, int tipsCount)
{
	BaseUIScreen::Init(setTransform, layerSetting);
	_isLock = false;

	ObjectFactory& factory = ObjectFactory::Instance();
	Transform worldTransform = Transform();
	LayerSetting layer = LayerSetting(true, false, Layer::MIDDLE);

	// äÓëb
	worldTransform = Transform(Vector2::zero(), Vector2::one(), this);
	_BGImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, false, layer);
	worldTransform = Transform(_INFORMATION_POS, Vector2::one(), this);
	_informationText = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_informationText->SetText(_INFORMATION_TEXT + std::to_string(tipsCount));
	// ÉçÉbÉN
	worldTransform = Transform(_LOCK_TEXT_POS, Vector2::one(), this);
	_lockText = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_lockText->SetText(_LOCK_TEXT);
	// ä«óùï˚ñ@
	worldTransform = Transform(_TIPS_TEXT_POS, Vector2::one(), this);
	_tipsText = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_tipsText->SetText(tipsText);
}

void EntityManagementTipsUI::Draw()
{
	_BGImage->Draw();
	_informationText->Draw();
	if (_isLock)
	{
		_lockText->Draw();
	}
	else
	{
		_tipsText->Draw();
	}
}