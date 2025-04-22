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

	if (prevText != _buttonText)
	{
		int w = GetDrawStringWidthToHandle(_buttonText.c_str(), strlen(_buttonText.c_str()), fontHandle);
		int h = GetFontSizeToHandle(fontHandle);

		int texW = w + 50;
		int texH = h + 50;

		int screen;
		textGraph = MakeScreen(texW, texH, TRUE);

		screen = GetDrawScreen();
		SetDrawScreen(textGraph);
		ClearDrawScreen();

		int drawX = texW / 2 - w / 2;
		int drawY = texH / 2 - h / 2;
		DrawStringToHandle(drawX, drawY, _buttonText.c_str(), GetColor(255, 255, 255), fontHandle);

		ScreenFlip();
		SetDrawScreen(screen);

		prevText = _buttonText; 
	}
}

void UIButton::Draw()
{
	// 描画
	BaseUI::Draw();

	// テキスト
	VECTOR pos = VGet(position.x, position.y , 0.0f);
	DrawBillboard3D(
		pos,
		0.5f, 0.5f,
		((objectSize.x + objectSize.y) / 2) ,
		0,
		textGraph,
		TRUE
	);
}

void UIButton::Teardown()
{
	// 破棄
	BaseUI::Teardown();

	if (textGraph != -1) 
	{
		DeleteGraph(textGraph);
		textGraph = -1;
	}
}