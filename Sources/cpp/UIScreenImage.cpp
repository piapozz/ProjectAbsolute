#include "../header/UIScreenImage.h"

void UIScreenImage::Init(Transform setTransform, bool fill, LayerSetting layerSetting)
{
	BaseUIScreen::Init(setTransform, layerSetting);
	_color = GetColor(0, 0, 0);
	_outLineColor = GetColor(205, 133, 63);
	_fill = fill;
	_onCursor = false;
	_onCursorColor = COLOR_YELLOW;
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

	// êFê›íË
	int color = -1;
	_onCursor ? color = _onCursorColor : color = _outLineColor;

	// ì‡ë§
	DrawBoxAA(x1, y1, x2, y2, _color, _fill);
	// òg
	DrawBoxAA(x1, y1, x2, y2, color, FALSE);
}

void UIScreenImage::OnCursor()
{
	_onCursor = true;
}

void UIScreenImage::NotOnCursor()
{
	_onCursor = false;
}