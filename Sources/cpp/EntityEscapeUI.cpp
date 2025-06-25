#include "../header/EntityEscapeUI.h"
#include "../header/ObjectFactory.h"

EntityEscapeUI::EntityEscapeUI(Transform setTransform, LayerSetting layerSetting, float defence[(int)Type::MAX])
{
	BaseUIScreen::Init(setTransform, layerSetting);
	_isLock = false;

	ObjectFactory& factory = ObjectFactory::Instance();
	Transform worldTransform = Transform(Vector2::zero(), Vector2::one(), this);
	LayerSetting layer = LayerSetting(true, false, Layer::MIDDLE);

	// 基礎
	worldTransform = Transform(Vector2::zero(), Vector2::one(), this);
	_BGImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, false, layer);
	_BGImage->SetOutLineColor(GetColor(255, 128, 0));
	worldTransform = Transform(_INFORMATION_POS, Vector2::one(), this);
	_informationText = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_informationText->SetText(_INFORMATION_TEXT);
	// ロック
	worldTransform = Transform(_LOCK_IMAGE_POS, _LOCK_IMAGE_SCALE, this);
	_lockImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, false, layer);
	worldTransform = Transform(_LOCK_TEXT_POS, Vector2::one(), this);
	_lockText = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_lockText->SetText(_LOCK_TEXT);
	// メルトカウント
	worldTransform = Transform(_MELTDOWN_IMAGE_POS, _MELTDOWN_IMAGE_SCALE, this);
	_meltdownImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, false, layer);
	worldTransform = Transform(_MELTDOWN_INFORMATION_POS, Vector2::one(), this);
	_meltdownInformation = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_meltdownInformation->SetText(_MELTDOWN_INFORMATION);
	worldTransform = Transform(_MELTDOWN_COUNT_POS, Vector2::one(), this);
	_meltdownCountText = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_meltdownCountText->SetText("X");
	// 防御耐性
	worldTransform = Transform(_DEFENCE_IMAGE_POS, _DEFENCE_IMAGE_SCALE, this);
	_defenceImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, false, layer);
	worldTransform = Transform(_DEFENCE_INFORMATION_POS, Vector2::one(), this);
	_defenceInformation = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_defenceInformation->SetText(_DEFENCE_INFORMATION);
	for (int i = 0; i < (int)Type::MAX; i++)
	{
		worldTransform = Transform(_DEFENCE_TEXT_POS[i], Vector2::one(), this);
		_defenceText[i] = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
		_defenceText[i]->SetText(std::to_string(defence[i]));
		_defenceText[i]->SetTextColor(ToColor((Type)i));
	}
}

void EntityEscapeUI::Draw()
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
		_meltdownImage->Draw();
		_meltdownInformation->Draw();
		_meltdownCountText->Draw();
		_defenceImage->Draw();
		_defenceInformation->Draw();
		for (int i = 0; i < (int)Type::MAX; i++)
		{
			_defenceText[i]->Draw();
		}
	}
}