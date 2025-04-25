#include "../header/UIScreenSlider.h"
#include "../header/CameraController.h"

void UIScreenSlider::Init(Vector2 setPosition, Vector2 setSize)
{
	_screenPos = setPosition;
	_color = -1;
	// ステージ座標に変換
	Vector2 stagePos = CameraController::GetScreen2StagePos(_screenPos);
	// 初期化
	BaseUI::Init(setPosition, setSize);
}

void UIScreenSlider::Proc()
{
	// アップデート
	BaseUI::Proc();
}

void UIScreenSlider::Draw()
{
	// 四角を描画
	int x1 = position.x - objectSize.x / 2;
	int y1 = position.y - objectSize.y / 2;
	int x2 = x1 + (objectSize.x * _value);
	int y2 = position.y + objectSize.y / 2;

	// 2D表示
	DrawBoxAA(x1, y1, x2, y2, _color, true);

	DrawUIBox();
	DrawUIText();

	// ステージ座標に変換
	Vector2 stagePos = CameraController::GetScreen2StagePos(_screenPos);
}

void UIScreenSlider::Teardown()
{
	// 破棄
	BaseUI::Teardown();
}