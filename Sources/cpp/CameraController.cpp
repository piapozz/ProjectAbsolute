#include "../header/CameraController.h"
#include <math.h>

CameraController::CameraController()
{
	position = VGet(0.0f, 10.0f, -20.0f);
	pitch = 0.0f;
	yaw = 0.0f;
	moveSpeed = 0.5f;
	rotateSpeed = 0.001f;

	isRightButtonPressed = false;
	GetMousePoint(&prevMouseX, &prevMouseY);
}

void CameraController::Update()
{
	HandleMouse();
	HandleKeyboard();
	UpdateCamera();
}

void CameraController::HandleMouse()
{
	int mouseX, mouseY;
	GetMousePoint(&mouseX, &mouseY);

	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0)
	{
		if (!isRightButtonPressed)
		{
			prevMouseX = -mouseX;
			prevMouseY = -mouseY;
			isRightButtonPressed = true;
		}

		int dx = -mouseX - prevMouseX;
		int dy = -mouseY - prevMouseY;

		yaw += dx * rotateSpeed;
		pitch += dy * rotateSpeed;
		pitch = max(-DX_PI_F / 2.0f + 0.01f, min(DX_PI_F / 2.0f - 0.01f, pitch)); // 上下90度制限

		prevMouseX = -mouseX;
		prevMouseY = -mouseY;
	} else
	{
		isRightButtonPressed = false;
	}

	// ホイールで前後移動
	int wheel = GetMouseWheelRotVol();
	if (wheel != 0)
	{
		VECTOR forward = VNorm(VGet(cosf(yaw) * cosf(pitch), sinf(pitch), sinf(yaw) * cosf(pitch)));
		position = VAdd(position, VScale(forward, wheel * 0.01f));
	}
}

void CameraController::HandleKeyboard()
{
	float currentSpeed = moveSpeed;
	if (CheckHitKey(KEY_INPUT_LSHIFT)) currentSpeed *= 5.0f;

	VECTOR forward = VNorm(VGet(cosf(yaw) * cosf(pitch), 0.0f, sinf(yaw) * cosf(pitch)));
	VECTOR right = VNorm(VGet(-sinf(yaw), 0.0f, cosf(yaw)));

	if (CheckHitKey(KEY_INPUT_W)) position = VAdd(position, VScale(forward, currentSpeed));
	if (CheckHitKey(KEY_INPUT_S)) position = VSub(position, VScale(forward, currentSpeed));
	if (CheckHitKey(KEY_INPUT_A)) position = VAdd(position, VScale(right, currentSpeed));
	if (CheckHitKey(KEY_INPUT_D)) position = VSub(position, VScale(right, currentSpeed));
	if (CheckHitKey(KEY_INPUT_E)) position.y += currentSpeed;
	if (CheckHitKey(KEY_INPUT_Q)) position.y -= currentSpeed;
}

void CameraController::UpdateCamera()
{
	VECTOR dir = VNorm(VGet(cosf(yaw) * cosf(pitch), sinf(pitch), sinf(yaw) * cosf(pitch)));
	VECTOR target = VAdd(position, dir);
	SetCameraPositionAndTarget_UpVecY(position, target);
}
