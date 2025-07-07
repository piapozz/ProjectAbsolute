#include "../header/UIScreenText.h"
#include "../header/UIManager.h"

void UIScreenText::Init(Transform setTransform, LayerSetting layerSetting)
{
	BaseUIScreen::Init(setTransform, layerSetting);
	_text = "";
	_textColor = GetColor(255, 255, 255);
	_fontSize = _DEFAULT_FONT_SIZE;
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
	Transform transformWorld = transform.GetWorldTransform();
	Vector2 position = transformWorld.position;
	int anchorX = position.x;
	int anchorY = position.y;
	DrawFormatStringToHandle(anchorX, anchorY, _textColor, UIManager::Instance().GetFontHandle(_fontSize), _text.c_str());
}
