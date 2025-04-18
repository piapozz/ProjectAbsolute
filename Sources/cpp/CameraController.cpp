#include "../header/CameraController.h"
#include "../header/Const.h"
#include <math.h>

CameraController::CameraController()
{
	position = VGet(100.0f, 100.0f, -100.0f);

	isRightButtonPressed = false;
	GetMousePoint(&prevMouseX, &prevMouseY);

	// ���ˉe�J�������Z�b�g�A�b�v����
	heightSize = 1000;
	SetupCamera_Ortho(heightSize);
	// �J�����̈ʒu�ƌ�����ݒ�
	SetCameraPositionAndTarget_UpVecY(position, VGet(100.0f, 100.0f, 100.0f));
	// �J�����̃N���b�s���O������ݒ�
	SetCameraNearFar(1.0f, 1000.0f);
}

void CameraController::Update()
{
	HandleMouse();
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
		float screenRatio = heightSize / WINDOW_HEIGHT;
		position = VGet(position.x + dx * screenRatio, position.y - dy * screenRatio, -100.0f);

		prevMouseX = -mouseX;
		prevMouseY = -mouseY;
	}
	else
	{
		isRightButtonPressed = false;
	}

	// �z�C�[���őO��ړ�
	int wheel = GetMouseWheelRotVol();
	if (wheel != 0)
		SetCameraOrtho(wheel);
}

void CameraController::UpdateCamera()
{
	VECTOR target = VGet(position.x, position.y, 100.0f);
	SetCameraPositionAndTarget_UpVecY(position, target);
}

void CameraController::SetCameraOrtho(int wheel)
{
	if (wheel > 0)
		heightSize -= 100;
	else if (wheel < 0)
		heightSize += 100;
	SetupCamera_Ortho(heightSize);
}