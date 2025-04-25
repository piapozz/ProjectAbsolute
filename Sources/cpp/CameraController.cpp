#include "../header/CameraController.h"
#include "../header/Const.h"
#include <math.h>

Vector2 CameraController::stagePosition;
float CameraController::heightSize;

CameraController::CameraController()
{
	// ���ˉe�J�������Z�b�g�A�b�v����
	heightSize = _MAX_HEIGHT_SIZE;
	SetupCamera_Ortho(heightSize);
	// �J�����̈ʒu�ƌ�����ݒ�
	stagePosition = Vector2(_DEFAULT_POS_X, _DEFAULT_POS_Y);
	VECTOR position = VGet(_DEFAULT_POS_X, _DEFAULT_POS_Y, _Z_POS_OFFSET);
	VECTOR target = VGet(_DEFAULT_POS_X, _DEFAULT_POS_Y, _Z_TARGET_FAR);
	SetCameraPositionAndTarget_UpVecY(position, target);
	// �J�����̃N���b�s���O������ݒ�
	SetCameraNearFar(1.0f, _Z_TARGET_FAR);
}

void CameraController::UpdateCamera()
{
	VECTOR position = VGet(stagePosition.x, stagePosition.y, _Z_POS_OFFSET);
	VECTOR target = VGet(position.x, position.y, _Z_TARGET_FAR);
	SetCameraPositionAndTarget_UpVecY(position, target);
	SetupCamera_Ortho(heightSize);
}

void CameraController::SetCameraOrtho(int wheel)
{
	if (wheel > 0 && heightSize > _MIN_HEIGHT_SIZE)
		heightSize -= 100;
	else if (wheel < 0 && heightSize < _MAX_HEIGHT_SIZE)
		heightSize += 100;
	SetupCamera_Ortho(heightSize);
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
	float screenRatio = heightSize / WINDOW_HEIGHT;
	stagePosition = Vector2(stagePosition.x + dx * screenRatio, stagePosition.y - dy * screenRatio);

	_prevCursorPos = screenPos;

	UpdateCamera();
}

void CameraController::WheelEvent(int up)
{
	SetCameraOrtho(up);
}

Vector2 CameraController::GetScreen2StagePos(Vector2 screenPos)
{
	// �g�k�ƒ��S���W����ϊ�
	float heightSize = CameraController::heightSize;
	Vector2 stageCentorPos = CameraController::stagePosition;
	float ratio = heightSize / WINDOW_HEIGHT;
	Vector2 screenCentor = Vector2(WINDOW_WIDTH, WINDOW_HEIGHT) / 2;
	// �X�N���[���̒��S���W����̋����Ɋg�k�������ăX�e�[�W�̒��S���W���狁�߂�
	Vector2 screenDistance = Vector2(screenPos.x - screenCentor.x, screenCentor.y - screenPos.y);
	return Vector2(stageCentorPos + screenDistance * ratio);
}