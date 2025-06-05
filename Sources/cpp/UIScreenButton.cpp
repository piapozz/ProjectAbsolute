#include "../header/UIScreenButton.h"
#include "../header/CameraController.h"

void UIScreenButton::Init(Vector2 setPosition, Vector2 setSize, bool fill, LayerSetting layerSetting)
{
	// 初期化
	BaseUIScreen::Init(setPosition, setSize, fill, layerSetting);
}

void UIScreenButton::Proc()
{
	// アップデート
	BaseUIScreen::Proc();
}

void UIScreenButton::Draw()
{
	DrawUIBox(GetColor(128, 128, 128));
	DrawUIText();
	BaseUIScreen::Draw();
}

void UIScreenButton::Teardown()
{
	// 破棄
	BaseUIScreen::Teardown();
}