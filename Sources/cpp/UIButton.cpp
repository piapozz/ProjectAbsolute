#include "../header/UIButton.h"

void UIButton::Init(Vector2 setPosition, Vector2 setSize)
{
	// 初期化
	BaseUI::Init(setPosition, setSize);
}

void UIButton::Proc()
{
	// アップデート
	BaseUI::Proc();
}

void UIButton::Draw()
{
	// 描画
	BaseUI::Draw();
}

void UIButton::Teardown()
{
	// 破棄
	BaseUI::Teardown();
}