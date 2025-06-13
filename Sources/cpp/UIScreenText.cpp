#include "../header/UIScreenText.h"

void UIScreenText::Init(Transform setTransform, LayerSetting layerSetting)
{
	BaseUIScreen::Init(setTransform, layerSetting);
	_text == "";
	_textColor = -1;
	fontHandle = CreateFontToHandle("�l�r �S�V�b�N", 24, 1);
	textGraph = MakeScreen(128, 32, TRUE);
	textSize = 100;
}

void UIScreenText::Proc()
{
	// �A�b�v�f�[�g
	BaseUIScreen::Proc();
}

void UIScreenText::Draw()
{
	// �`��
	BaseUIScreen::Draw();
	DrawUIText();
}

void UIScreenText::Teardown()
{
	// �j��
	BaseUIScreen::Teardown();
}

void UIScreenText::DrawUIText()
{
	if (_text == "") return;
	// �e�L�X�g
	Transform transformWorld = transform.GetWorldTransform();
	Vector2 position = transformWorld.position;
	int anchorX = position.x;
	int anchorY = position.y;
	DrawFormatStringToHandle(anchorX, anchorY, _textColor, fontHandle, _text.c_str());
}
