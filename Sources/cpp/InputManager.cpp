#include "../header/InputManager.h"

InputManager::InputManager()
{
	
}

InputManager::~InputManager()
{

}

bool InputManager::IsClick(int button)
{
	// �����l�̏ꍇ�����ɏ����𔲂���
	if (button != MOUSE_INPUT_LEFT && button != MOUSE_INPUT_RIGHT) return false;
	// �}�E�X�̏�Ԃ��擾
	int mouseInput, posX, posY, isUp;
	GetMouseInputLog2(&mouseInput, &posX, &posY, &isUp, TRUE);
	// �����ꂽ�Ƃ��̃J�[�\�����W��ێ�
	if (!isUp)
	{
		if (mouseInput == MOUSE_INPUT_LEFT)
			_oldLClickScreenPos = Vector2((float)posX, (float)posY);
		else if (mouseInput == MOUSE_INPUT_RIGHT)
			_oldRClickScreenPos = Vector2((float)posX, (float)posY);
	}

	return button == mouseInput && isUp;
}

Vector2 InputManager::GetCursorScreenPos()
{
	int posx, posy;
	GetMousePoint(&posx, &posy);
	return Vector2((float)posx, (float)posy);
}

Vector2 InputManager::GetCursorWorldPos(Vector2 screenPos)
{
	VECTOR screenVec = VGet(screenPos.x, screenPos.y, 0.5f);
	VECTOR worldVec = ConvScreenPosToWorldPos(screenVec);
	return Vector2(worldVec.x, worldVec.y);
}

void InputManager::ExecuteCallback()
{
	// �J�[�\�����W�̎擾
	Vector2 cursorScreenPos = GetCursorScreenPos();

	// ���N���b�N���������Ƃ��̏���
	if (_LPushAction != NULL && IsClick(MOUSE_INPUT_LEFT))
		_LPushAction(cursorScreenPos);
	// �E�N���b�N���������Ƃ��̏���
	if (_RPushAction != NULL && IsClick(MOUSE_INPUT_RIGHT))
		_RPushAction(cursorScreenPos);
	// ���N���b�N�𗣂����Ƃ��̏���
	if (_LReleaseAction != NULL && IsClick(MOUSE_INPUT_LEFT))
		_LReleaseAction(cursorScreenPos, _oldLClickScreenPos);
	// �E�N���b�N�𗣂����Ƃ��̏���
	if (_RReleaseAction != NULL && IsClick(MOUSE_INPUT_RIGHT))
		_RReleaseAction(cursorScreenPos, _oldRClickScreenPos);
	// �z�C�[������]�������Ƃ��̏���
	int wheelRot = GetMouseWheelRotVol();
	if (_WheelRotAction != NULL && wheelRot != 0)
		_WheelRotAction(cursorScreenPos, wheelRot);
	// Escape�L�[���������Ƃ��̏���
	if (_EscapePushAction != NULL && CheckHitKey(KEY_INPUT_ESCAPE))
		_EscapePushAction();
}
