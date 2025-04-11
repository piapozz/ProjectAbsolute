#include "../header/InputManager.h"

InputManager::InputManager()
{
	cursorPos = {0,0};
}

InputManager::~InputManager()
{

}

/// <summary>
/// �N���b�N��������Ă��邩�𔻒�
/// </summary>
/// <param name="button"></param>
/// <returns></returns>
bool InputManager::CheckClick(MouseButton button)
{
	// �����l�̏ꍇ�����ɏ����𔲂���
	if(button == MouseButton::NONE) return false;
	// �}�E�X�̏�Ԃ��擾
	int mouseInput = GetMouseInput();
	// ���茋�ʂ��L���b�V��
	bool onClick = (mouseInput & button) && !(oldMouseInput & button);
	oldMouseInput = mouseInput;

	return onClick;
}

/// <summary>
/// �J�[�\�����̍X�V
/// </summary>
/// <param name="mouseStatus"></param>
void InputManager::UpdataMouseCursor(MouseStatus mouseStatus)
{
	GetMousePoint(&mouseStatus.CURSOR_POS_X,&mouseStatus.CURSOR_POS_Y);
}

/// <summary>
/// �R�[���o�b�N�Őݒ肳�ꂽ�֐������s
/// </summary>
void InputManager::ExecuteCallback()
{
	if(callbackFunc == NULL) return;
	callbackFunc();
}

InputManager::MouseStatus InputManager::GetCursorPos() { return cursorPos; }
void InputManager::SetCallback(std::function<void()> callback) { callbackFunc = callback; }