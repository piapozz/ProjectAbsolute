#include "../header/CameraController.h"
#include "../header/Const.h"
#include <math.h>

CameraController::CameraController()
{
	_position = VGet(100.0f, 100.0f, -100.0f);

	// 正射影カメラをセットアップする
	_heightSize = 1000;
	SetupCamera_Ortho(_heightSize);
	// カメラの位置と向きを設定
	SetCameraPositionAndTarget_UpVecY(_position, VGet(100.0f, 100.0f, 100.0f));
	// カメラのクリッピング距離を設定
	SetCameraNearFar(1.0f, 1000.0f);
}

void CameraController::UpdateCamera()
{
	VECTOR target = VGet(_position.x, _position.y, 100.0f);
	SetCameraPositionAndTarget_UpVecY(_position, target);
	SetupCamera_Ortho(_heightSize);
}

void CameraController::SetCameraOrtho(int wheel)
{
	if (wheel > 0 && _heightSize > MIN_HEIGHT_SIZE)
		_heightSize -= 100;
	else if (wheel < 0 && _heightSize < MAX_HEIGHT_SIZE)
		_heightSize += 100;
	SetupCamera_Ortho(_heightSize);
}

void CameraController::RPushEvent(Vector2 screenPos)
{
	_pushPos = screenPos;
	_prevCursorPos = _pushPos;
}

void CameraController::RDrackEvent(Vector2 screenPos)
{
	int dx = _prevCursorPos.x - screenPos.x;
	int dy = _prevCursorPos.y - screenPos.y;
	float screenRatio = _heightSize / WINDOW_HEIGHT;
	_position = VGet(_position.x + dx * screenRatio, _position.y - dy * screenRatio, -100.0f);

	_prevCursorPos = screenPos;

	UpdateCamera();
}

void CameraController::WheelEvent(int up)
{
	SetCameraOrtho(up);
}