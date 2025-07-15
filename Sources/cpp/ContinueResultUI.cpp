#include "../header/ContinueResultUI.h"
#include "../header/ObjectFactory.h"
#include "../header/UIScreen.h"

ContinueResultUI::ContinueResultUI()
{
	Init();
}

void ContinueResultUI::Init()
{
	BaseUIScreen::Init(_TRANSFORM, _DEFAULT_LAYER);
	ObjectFactory& factory = ObjectFactory::Instance();
	Vector2 position = transform.position;
	Vector2 scale = transform.scale;
	Transform worldTransform = Transform();
	LayerSetting layer = LayerSetting(true, false, Layer::MIDDLE);

	// Šî‘b
	worldTransform = Transform(Vector2().zero(), Vector2().one(), this);
	_BGImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, true, layer);
	_BGImage->SetColor(COLOR_BLACK);
	worldTransform = Transform(_INFORMATION_POS, Vector2().one(), this);
	_informationText = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	_informationText->SetText(_INFORMATION_TEXT);
	worldTransform = Transform(_CONTINUE_POS, _CONTINUE_SCALE, this);
	layer = LayerSetting(false, true, Layer::MIDDLE);
	_continueButton = factory.CreateWithArgs<UIScreenButton>(worldTransform, true, layer);
	_continueButton->SetText(_CONTINUE_TEXT);
}

void ContinueResultUI::Draw()
{
	_BGImage->Draw();
	_informationText->Draw();
	_continueButton->Draw();
}

void ContinueResultUI::SetCallback(std::function<void()> setCallback)
{
	_continueButton->SetCallback(setCallback);
}

void ContinueResultUI::SetActive(bool setActive)
{
	active = setActive;
	_continueButton->SetActive(setActive);
}