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

	bool CheckClick(MouseButton button);
	void ExecuteCallback();
	void UpdataMouseCursor(MouseStatus mouseStatus);

	inline MouseStatus GetCursorPos();
	inline void SetCallback(std::function<void()> callback);

private:
	// �}�E�X�J�[�\�����W��ێ�
	MouseStatus cursorPos;
	// Function��ێ�����ϐ�
	std::function<void()> callbackFunc;
	// �}�E�X�̉ߋ��̏�Ԃ��i�[
	int oldMouseInput;
};
