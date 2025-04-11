#pragma once
#include "DxLib.h"
#include "functional"

/*
 * Sein
 * �L�[�{�[�h�ƃ}�E�X�̓��͂��󂯎��A�C�x���g���Ǘ�
 */
class InputManager
{
public:
	// �}�E�X�����Ǘ�
	struct MouseStatus
	{
		int CURSOR_POS_X;
		int CURSOR_POS_Y;
	};

	// �}�E�X�̃{�^���̎�ޒ�`
	enum MouseButton
	{
		NONE = -1,
		LEFT_CLICK = MOUSE_INPUT_LEFT,
		RIGHT_CLICK = MOUSE_INPUT_RIGHT ,
	};

	InputManager();
	~InputManager();

	/// <summary>
	/// �N���b�N��������Ă��邩�𔻒�
	/// </summary>
	/// <param name="button"></param>
	/// <returns></returns>
	void OnClick(MouseButton button);
	/// <summary>
	/// �R�[���o�b�N�Őݒ肳�ꂽ�֐������s
	/// </summary>
	void ExecuteCallback();
	/// <summary>
	/// �J�[�\�����̍X�V
	/// </summary>
	/// <param name="mouseStatus"></param>
	void UpdataMouseCursor(MouseStatus mouseStatus);

	inline MouseStatus GetCursorPos(){ return _cursorPos; }
	inline void SetCallback(std::function<void()> callback){ _ClickAction = callback; }

private:
	// �}�E�X�J�[�\�����W��ێ�
	MouseStatus _cursorPos;
	// Function��ێ�����ϐ�
	std::function<void()> _ClickAction;
	// �}�E�X�̉ߋ��̏�Ԃ��i�[
	int _oldMouseInput;
};
