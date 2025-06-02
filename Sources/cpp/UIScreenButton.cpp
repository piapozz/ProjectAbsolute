#include "../header/UIScreenButton.h"
#include "../header/CameraController.h"

void UIScreenButton::Init(Vector2 setPosition, Vector2 setSize)
{
	// 初期化
	BaseUIScreen::Init(setPosition, setSize);
}

void UIScreenButton::Proc()
{
	// アップデート
	BaseUIScreen::Proc();
}

void UIScreenButton::Draw()
{
	BaseUIScreen::Draw();
}

void UIScreenButton::Teardown()
{
	// 破棄
	BaseUIScreen::Teardown();
}