#include "../header/CameraController.h"
#include "../header/Const.h"
#include <math.h>

CameraController::CameraController()
{
	position = VGet(100.0f, 100.0f, -100.0f);

	isRightButtonPressed = false;
	GetMousePoint(&prevMouseX, &prevMouseY);

	// 正射影カメラをセットアップする
	heightSize = 1000;
	SetupCamera_Ortho(heightSize);
	// カメラの位置と向きを設定
	SetCameraPositionAndTarget_UpVecY(position, VGet(100.0f, 100.0f, 100.0f));
	// カメラのクリッピング距離を設定
	SetCameraNearFar(1.0f, 1000.0f);
}

void CameraController::Update()
{
	HandleMouse();
	UpdateCamera();
}

void CameraController::HandleMouse()
{
	if (isRightButtonPressed)
	{
		int dx = -_clickPos.x - prevMouseX;
		int dy = -_clickPos.y - prevMouseY;
		float screenRatio = heightSize / WINDOW_HEIGHT;
		position = VGet(position.x + dx * screenRatio, position.y - dy * screenRatio, -100.0f);
	}

	prevMouseX = -_clickPos.x;
	prevMouseY = -_clickPos.y;
}

void CameraController::UpdateCamera()
{
	VECTOR target = VGet(position.x, position.y, 100.0f);
	SetCameraPositionAndTarget_UpVecY(position, target);
}

void CameraController::SetCameraOrtho(int wheel)
{
	if (wheel > 0 && heightSize > MIN_HEIGHT_SIZE)
		heightSize -= 100;
	else if (wheel < 0 && heightSize < MAX_HEIGHT_SIZE)
		heightSize += 100;
	SetupCamera_Ortho(heightSize);
}

void CameraController::RPushEvent(Vector2 screenPos)
{
	isRightButtonPressed = true;
	_clickPos = screenPos;
}

void CameraController::RReleaseEvent()
{
	isRightButtonPressed = false;
}

void CameraController::WheelEvent(int up)
{
	SetCameraOrtho(up);
}