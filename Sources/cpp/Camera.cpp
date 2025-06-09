#include "../header/Camera.h"
#include "../header/Const.h"
#include <math.h>

Camera* Camera::instance;

Camera::Camera()
{
	instance = this;
	// 正射影カメラをセットアップする
	_heightSize = _MAX_HEIGHT_SIZE;
	SetupCamera_Ortho(_heightSize);
	// カメラの位置と向きを設定
	position = Vector2(_DEFAULT_POS_X, _DEFAULT_POS_Y);
	VECTOR position = VGet(_DEFAULT_POS_X, _DEFAULT_POS_Y, _Z_POS_OFFSET);
	VECTOR target = VGet(_DEFAULT_POS_X, _DEFAULT_POS_Y, _Z_TARGET_FAR);
	SetCameraPositionAndTarget_UpVecY(position, target);
	// カメラのクリッピング距離を設定
	SetCameraNearFar(1.0f, _Z_TARGET_FAR);
}

void Camera::UpdateCamera()
{
	VECTOR cameraPosition = VGet(position.x, position.y, _Z_POS_OFFSET);
	VECTOR target = VGet(position.x, position.y, _Z_TARGET_FAR);
	SetCameraPositionAndTarget_UpVecY(cameraPosition, target);
	SetupCamera_Ortho(_heightSize);
}

void Camera::SetCameraOrtho(int wheel)
{
	if (wheel > 0 && _heightSize > _MIN_HEIGHT_SIZE)
		_heightSize -= 100;
	else if (wheel < 0 && _heightSize < _MAX_HEIGHT_SIZE)
		_heightSize += 100;
	SetupCamera_Ortho(_heightSize);
}

void Camera::RPushEvent(Vector2 screenPos)
{
	_pushPos = screenPos;
	_prevCursorPos = _pushPos;
}

void Camera::RDrackEvent(Vector2 screenPos)
{
	int dx = _prevCursorPos.x - screenPos.x;
	int dy = _prevCursorPos.y - screenPos.y;
	float screenRatio = _heightSize / WINDOW_HEIGHT;
	position = Vector2(position.x + dx * screenRatio, position.y - dy * screenRatio);

	_prevCursorPos = screenPos;

	UpdateCamera();
}

void Camera::WheelEvent(int up)
{
	SetCameraOrtho(up);
}