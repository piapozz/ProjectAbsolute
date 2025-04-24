#include "../header/UIScreenButton.h"

void UIScreenButton::Init(Vector2 setPosition, Vector2 setSize)
{
	// 初期化
	BaseUI::Init(setPosition, setSize);
}

void UIScreenButton::Proc()
{
	// アップデート
	BaseUI::Proc();
}

void UIScreenButton::Draw()
{
	// 描画
	// テキスト

}

void UIScreenButton::Teardown()
{
	// 破棄
	BaseUI::Teardown();
}