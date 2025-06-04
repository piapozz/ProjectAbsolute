#include "../header/BaseUIScreen.h"
#include "../header/CameraController.h"
#include "../header/ObjectManager.h"

void BaseUIScreen::Init(Vector2 setPosition, Vector2 setSize, bool fill)
{
	_text == "";
	_textColor = -1;
	_screenPos = setPosition;
	_fill = fill;
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
	_outLineColor = GetColor(255, 255, 255);
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

	DrawBoxAA(x1, y1, x2, y2, color, _fill);
	DrawBoxAA(x1, y1, x2, y2, _outLineColor, FALSE);
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
	_outLineColor = GetColor(0, 255, 255);
}

void BaseUIScreen::NotOnCursor()
{
	_outLineColor = GetColor(255, 255, 255);
}