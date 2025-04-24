#include "../header/BaseUI.h"
#include "../header/ObjectManager.h"

void BaseUI::Init(Vector2 setPosition, Vector2 setSize)
{
	_fontHandle = CreateFontToHandle("ＭＳ ゴシック", 24, 1);
	_textGraph = MakeScreen(128, 32, TRUE); 
	position = setPosition;
	objectSize = setSize;
	objectType = ObjectType::UI;
	layer = Layer::OBJECT;
	ObjectManager::AddObject(this);
	_textSize = 100;
}

void BaseUI::Proc()
{
	// アップデート
	BaseObject::Proc();

	if (prevText != _text)
	{
		int w = GetDrawStringWidthToHandle(_text.c_str(), strlen(_text.c_str()), _fontHandle);
		int h = GetFontSizeToHandle(_fontHandle);

		int texW = w + 50;
		int texH = h + 50;

		int screen;
		_textGraph = MakeScreen(texW, texH, TRUE);

		screen = GetDrawScreen();
		SetDrawScreen(_textGraph);
		ClearDrawScreen();

		int drawX = texW / 2 - w / 2;
		int drawY = texH / 2 - h / 2;
		DrawStringToHandle(drawX, drawY, _text.c_str(), GetColor(255, 255, 255), _fontHandle);

		ScreenFlip();
		SetDrawScreen(screen);

		prevText = _text;
	}
}

void BaseUI::Draw()
{
	// 描画
	BaseObject::Draw();

	// 四角を描画
	int x1 = position.x + objectSize.x / 2;
	int y1 = position.y + objectSize.y / 2;
	int x2 = position.x - objectSize.x / 2;
	int y2 = position.y - objectSize.y / 2;

	VECTOR Pos1 = VGet(x1, y1, 0);
	VECTOR Pos2 = VGet(x2, y1, 0);
	VECTOR Pos3 = VGet(x2, y2, 0);
	VECTOR Pos4 = VGet(x1, y2, 0);

	DrawLine3D(Pos1, Pos2, GetColor(255, 255, 255));
	DrawLine3D(Pos2, Pos3, GetColor(255, 255, 255));
	DrawLine3D(Pos3, Pos4, GetColor(255, 255, 255));
	DrawLine3D(Pos4, Pos1, GetColor(255, 255, 255));

	// テキスト
	VECTOR pos = VGet(position.x, position.y, 0.0f);
	DrawBillboard3D(
		pos,
		0.5f, 0.5f,
		_textSize,
		0,
		_textGraph,
		TRUE
	);
}

void BaseUI::Teardown()
{
	// 破棄
	BaseObject::Teardown();

	if (_textGraph != -1)
	{
		DeleteGraph(_textGraph);
		_textGraph = -1;
	}
}

void BaseUI::SetActive(bool active)
{
	if (active)
	{
		layer = Layer::UI;
	}
	else
	{
		layer = Layer::NONE_DRAW;
	}
}