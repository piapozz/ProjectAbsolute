#include "../header/UIScreenImage.h"

void UIScreenImage::Init(Transform setTransform, bool fill, LayerSetting layerSetting)
{
	BaseUIScreen::Init(setTransform, layerSetting);
	_fill = fill;
}

void UIScreenImage::Proc()
{
	// �A�b�v�f�[�g
	BaseUIScreen::Proc();
}

void UIScreenImage::Draw()
{
	// �`��
	BaseUIScreen::Draw();
	DrawUIBox();
}

void UIScreenImage::Teardown()
{
	// �j��
	BaseUIScreen::Teardown();
}

void UIScreenImage::DrawUIBox(int color)
{
	// �l�p��`��
	Vector2 position = transform.GetWorldPosition();
	Vector2 scale = transform.scale;
	int x1 = position.x + scale.x / 2;
	int y1 = position.y + scale.y / 2;
	int x2 = position.x - scale.x / 2;
	int y2 = position.y - scale.y / 2;

	DrawBoxAA(x1, y1, x2, y2, color, _fill);
	DrawBoxAA(x1, y1, x2, y2, _outLineColor, FALSE);
}

void UIScreenImage::OnCursor()
{
	_outLineColor = GetColor(0, 255, 255);
}

void UIScreenImage::NotOnCursor()
{
	_outLineColor = GetColor(255, 255, 255);
}