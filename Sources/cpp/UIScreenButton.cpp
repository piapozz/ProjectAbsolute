#include "../header/UIScreenButton.h"
#include "../header/CameraController.h"

void UIScreenButton::Init(Vector2 setPosition, Vector2 setSize)
{
	_screenPos = setPosition;
	// ステージ座標に変換
	Vector2 stagePos = CameraController::GetScreen2StagePos(_screenPos);
	// 初期化
	BaseUI::Init(stagePos, setSize);
}

void UIScreenButton::Proc()
{
	// アップデート
	BaseUI::Proc();
}

void UIScreenButton::Draw()
{
	DrawUIBox();
	DrawUIText();

	// ステージ座標に変換
	Vector2 stagePos = CameraController::GetScreen2StagePos(_screenPos);
}

void UIScreenButton::Teardown()
{
	// 破棄
	BaseUI::Teardown();
}