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
	if (_text.empty()) return;

	// ワールド座標取得
	Transform transformWorld = transform.GetWorldTransform();
	Vector2 position = transformWorld.position;

	// テキストサイズ取得
	int fontHandle = UIManager::Instance().GetFontHandle(_fontSize);
	int textWidth = GetDrawFormatStringWidthToHandle(fontHandle, _text.c_str());

	// 中央揃えのためにx座標を補正
	int anchorX = position.x - textWidth / 2;
	int anchorY = position.y;

	DrawFormatStringToHandle(anchorX, anchorY, _textColor, fontHandle, _text.c_str());
}