#include "../header/UIScreenText.h"

void UIScreenText::Init(Transform setTransform, LayerSetting layerSetting)
{
	BaseUIScreen::Init(setTransform, layerSetting);
	_text == "";
	_textColor = -1;
	fontHandle = CreateFontToHandle("ＭＳ ゴシック", 24, 1);
	textGraph = MakeScreen(128, 32, TRUE);
	textSize = 100;
}

void UIScreenText::Proc()
{
	// アップデート
	BaseUIScreen::Proc();
}

void UIScreenText::Draw()
{
	// 描画
	BaseUIScreen::Draw();
	DrawUIText();
}

void UIScreenText::Teardown()
{
	// 破棄
	BaseUIScreen::Teardown();
}

void UIScreenText::DrawUIText()
{
	if (_text == "") return;
	// テキスト
	Vector2 position = transform.GetWorldPosition();
	int anchorX = position.x;
	int anchorY = position.y;
	DrawFormatStringToHandle(anchorX, anchorY, _textColor, fontHandle, _text.c_str());
}
