#include "../header/InputManager.h"

InputManager::InputManager()
{
	_cursorPos = {0, 0};
}

InputManager::~InputManager()
{

}

void InputManager::OnClick(MouseButton button)
{
	// �����l�̏ꍇ�����ɏ����𔲂���
	if (button == MouseButton::NONE) return;
	// �}�E�X�̏�Ԃ��擾
	int mouseInput = GetMouseInput();
	// ���茋�ʂ��L���b�V��
	bool onClick = (mouseInput & button) && !(_oldMouseInput & button);
	_oldMouseInput = mouseInput;

	if (onClick) ExecuteCallback();
}

void InputManager::UpdataMouseCursor(MouseStatus mouseStatus)
{
	GetMousePoint(&mouseStatus.CURSOR_POS_X, &mouseStatus.CURSOR_POS_Y);
}

void InputManager::ExecuteCallback()
{
	if (_ClickAction == NULL) return;
	_ClickAction();
}
