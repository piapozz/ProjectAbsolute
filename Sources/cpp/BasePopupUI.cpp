#include "../header/BasePopupUI.h"
#include "../header/ObjectFactory.h"
#include "../header/UIScreen.h"

BasePopupUI::BasePopupUI()
{
	Init();
}

void BasePopupUI::Init()
{
	BaseUIScreen::Init(TRANSFORM, DEFAULT_LAYER);
	ObjectFactory& factory = ObjectFactory::Instance();
	Vector2 position = transform.position;
	Vector2 scale = transform.scale;
	Transform worldTransform = Transform();
	LayerSetting layer = LayerSetting(true, false, Layer::MIDDLE);

	// Šî‘b
	worldTransform = Transform(Vector2().zero(), Vector2().one(), this);
	BGImage = factory.CreateWithArgs<UIScreenImage>(worldTransform, true, layer);
	BGImage->SetColor(COLOR_BLACK);
	worldTransform = Transform(INFORMATION_POS, Vector2().one(), this);
	informationText = factory.CreateWithArgs<UIScreenText>(worldTransform, layer);
	worldTransform = Transform(CONTINUE_POS, CONTINUE_SCALE, this);
	layer = LayerSetting(false, true, Layer::MIDDLE);
	button = factory.CreateWithArgs<UIScreenButton>(worldTransform, true, layer);
}

void BasePopupUI::Draw()
{
	BGImage->Draw();
	informationText->Draw();
	button->Draw();
}

void BasePopupUI::SetCallback(std::function<void()> setCallback)
{
	button->SetCallback(setCallback);
}

void BasePopupUI::SetActive(bool setActive)
{
	active = setActive;
	button->SetActive(setActive);
}