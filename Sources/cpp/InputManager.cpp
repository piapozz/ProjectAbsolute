#include "../header/InputManager.h"

InputManager::InputManager()
{
	_isLPressed = false;
	_isRPressed = false;
}

InputManager::~InputManager()
{

}

int InputManager::CheckClickState()
{
	// �}�E�X�̏�Ԃ��擾
	int mouseInput, posX, posY, isUp = -1;
	if (GetMouseInputLog2(&mouseInput, &posX, &posY, &isUp, TRUE) < 0) return -1;
	// �N���b�N����ێ�
	if (mouseInput == MOUSE_INPUT_LEFT)
	{
		_LClickState = isUp;
		if (isUp == MOUSE_INPUT_LOG_DOWN)
		{
			_isLPressed = true;
			_oldLClickScreenPos = Vector2((float)posX, (float)posY);
		}
		else if (isUp == MOUSE_INPUT_LOG_UP)
			_isLPressed = false;
	}
	else if (mouseInput == MOUSE_INPUT_RIGHT)
	{
		_RClickState = isUp;
		if (isUp == MOUSE_INPUT_LOG_DOWN)
		{
			_isRPressed = true;
			_oldRClickScreenPos = Vector2((float)posX, (float)posY);
		}
		else if (isUp == MOUSE_INPUT_LOG_UP)
			_isRPressed = false;
	}
	return mouseInput;
}

Vector2 InputManager::GetCursorScreenPos()
{
	int posx, posy;
	GetMousePoint(&posx, &posy);
	return Vector2((float)posx, (float)posy);
}

void InputManager::ExecuteCallback()
{
	// �J�[�\�����W�̎擾
	Vector2 cursorScreenPos = GetCursorScreenPos();
	// �N���b�N�̏�Ԃ��m�F
	int currentMouseInput = CheckClickState();

	// ���N���b�N
	if (currentMouseInput == MOUSE_INPUT_LEFT)
	{
		if (_LPushAction != NULL && _LClickState == MOUSE_INPUT_LOG_DOWN)
			_LPushAction(cursorScreenPos);
		else if (_LReleaseAction != NULL && _LClickState == MOUSE_INPUT_LOG_UP)
			_LReleaseAction(cursorScreenPos, _oldLClickScreenPos);
	}
	// �h���b�N���Ă���Ƃ�
	if (_LDrackAction != NULL && _isLPressed)
		_LDrackAction(cursorScreenPos);

	// �E�N���b�N
	if (currentMouseInput == MOUSE_INPUT_RIGHT)
	{
		if (_RPushAction != NULL && _RClickState == MOUSE_INPUT_LOG_DOWN)
			_RPushAction(cursorScreenPos);
		else if (_RReleaseAction != NULL && _RClickState == MOUSE_INPUT_LOG_UP)
			_RReleaseAction(cursorScreenPos, _oldRClickScreenPos);
	}
	// �h���b�N���Ă���Ƃ�
	if (_RDrackAction != NULL && _isRPressed)
		_RDrackAction(cursorScreenPos);

	// �z�C�[������]�������Ƃ��̏���
	int wheelRot = GetMouseWheelRotVol();
	if (_WheelRotAction != NULL && wheelRot != 0)
		_WheelRotAction(cursorScreenPos, wheelRot);
	// Escape�L�[���������Ƃ��̏���
	if (_EscapePushAction != NULL && CheckHitKey(KEY_INPUT_ESCAPE))
		_EscapePushAction();
}

