#include "../header/BaseUIScreen.h"
#include "../header/CameraController.h"

void BaseUIScreen::Init(Vector2 setPosition, Vector2 setSize)
{
	_text == "";
	_textColor = -1;
	// 初期化
	BaseUI::Init(setPosition, setSize);
}

void BaseUIScreen::Proc()
{
	// アップデート
	BaseUI::Proc();
}

void BaseUIScreen::Draw()
{
	// 描画
	BaseUI::Draw();
}

void BaseUIScreen::Teardown()
{
	// 破棄
	BaseUI::Teardown();
}

void BaseUIScreen::DrawUIBox()
{
	// 四角を描画
	int x1 = position.x + objectSize.x / 2;
	int y1 = position.y + objectSize.y / 2;
	int x2 = position.x - objectSize.x / 2;
	int y2 = position.y - objectSize.y / 2;

	// 2D表示
	DrawBoxAA(x1, y1, x2, y2, GetColor(255, 255, 255), false);

	// ステージ座標に変換
	Vector2 stagePos = CameraController::GetScreen2StagePos(_screenPos);
}

void BaseUIScreen::DrawUIText()
{
	if (_text == "") return;
	// テキスト
	int anchorX = position.x;
	int anchorY = position.y;
	DrawFormatStringToHandle(anchorX, anchorY, _textColor, fontHandle, _text);
}