#include "../header/BaseUIScreen.h"
#include "../header/CameraController.h"
#include "../header/ObjectManager.h"

void BaseUIScreen::Init(Vector2 setPosition, Vector2 setSize)
{
	_text == "";
	_textColor = -1;
	_screenPos = setPosition;
	// ステージ座標に変換
	position = CameraController::GetScreen2StagePos(_screenPos);
	fontHandle = CreateFontToHandle("ＭＳ ゴシック", 24, 1);
	textGraph = MakeScreen(128, 32, TRUE);
	position = setPosition;
	objectSize = setSize;
	objectType = ObjectType::SCREEN_UI;
	layer = Layer::OBJECT;
	ObjectManager::instance->AddObject(this);
	textSize = 100;
}

void BaseUIScreen::Proc()
{
	// アップデート
	BaseObject::Proc();
}

void BaseUIScreen::Draw()
{
	// 描画
	BaseObject::Draw();
}

void BaseUIScreen::Teardown()
{
	// 破棄
	BaseObject::Teardown();
}

void BaseUIScreen::DrawUIBox(int color)
{
	// 四角を描画
	int x1 = position.x + objectSize.x / 2;
	int y1 = position.y + objectSize.y / 2;
	int x2 = position.x - objectSize.x / 2;
	int y2 = position.y - objectSize.y / 2;

	if (color == NULL)
		DrawBoxAA(x1, y1, x2, y2, GetColor(255, 255, 255), false);
	else
		DrawBoxAA(x1, y1, x2, y2, color, true);
}

void BaseUIScreen::DrawUIText()
{
	if (_text == "") return;
	// テキスト
	int anchorX = position.x;
	int anchorY = position.y;
	DrawFormatStringToHandle(anchorX, anchorY, _textColor, fontHandle, _text.c_str());
}

void BaseUIScreen::OnCursor()
{
	beforeOnCursor = true;
	DrawUIBox();
}