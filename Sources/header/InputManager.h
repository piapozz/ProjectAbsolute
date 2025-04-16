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
	inline void SetLClickCallback(std::function<void()> Callback){ _LPushAction = Callback; }
	inline void SetRClickCallback(std::function<void()> Callback){ _RPushAction = Callback; }
	inline void SetLReleaseCallback(std::function<void()> Callback){ _LReleaseAction = Callback; }
	inline void SetRReleaseCallback(std::function<void()> Callback){ _RReleaseAction = Callback; }

private:
	// �}�E�X�J�[�\�����W��ێ�
	MouseStatus _cursorPos;
	// ���N���b�N���������Ƃ��̃R�[���o�b�N
	std::function<void()> _LPushAction;
	// �E�N���b�N���������Ƃ��̃R�[���o�b�N
	std::function<void()> _RPushAction;
	// ���N���b�N�𗣂����Ƃ��̃R�[���o�b�N
	std::function<void()> _LReleaseAction;
	// �E�N���b�N�𗣂����Ƃ��̃R�[���o�b�N
	std::function<void()> _RReleaseAction;
	// �}�E�X�̉ߋ��̏�Ԃ��i�[
	int _oldMouseInput;
};
