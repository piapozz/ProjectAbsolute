#include "../header/UIScreenImage.h"

void UIScreenImage::Init(Transform setTransform, bool fill, LayerSetting layerSetting)
{
	BaseUIScreen::Init(setTransform, layerSetting);
	_color = GetColor(128, 128, 128);
	_outLineColor = COLOR_WHITE;
	_fill = fill;
	_onCorsor = false;
}

void UIScreenImage::Proc()
{
	// ÉAÉbÉvÉfÅ[Ég
	BaseUIScreen::Proc();
}

void UIScreenImage::Draw()
{
	// ï`âÊ
	BaseUIScreen::Draw();
	DrawUIBox();
}

void UIScreenImage::Teardown()
{
	// îjä¸
	BaseUIScreen::Teardown();
}

void UIScreenImage::DrawUIBox()
{
	// éläpÇï`âÊ
	Transform transformWorld = transform.GetWorldTransform();
	Vector2 position = transformWorld.position;
	Vector2 scale = transformWorld.scale;
	int x1 = position.x + scale.x / 2;
	int y1 = position.y + scale.y / 2;
	int x2 = position.x - scale.x / 2;
	int y2 = position.y - scale.y / 2;

	DrawBoxAA(x1, y1, x2, y2, _color, _fill);
	if (_onCorsor)
		DrawBoxAA(x1, y1, x2, y2, COLOR_ON_CORSOR, FALSE);
	else
		DrawBoxAA(x1, y1, x2, y2, _outLineColor, FALSE);
}

void UIScreenImage::OnCursor()
{
	_onCorsor = true;
}

void UIScreenImage::NotOnCursor()
{
	_onCorsor = false;
}