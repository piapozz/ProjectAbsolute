#pragma once
#include "DxLib.h"
#include "functional"
#include "../header/CommonModule.h"

/*
 * Sein
 * �L�[�{�[�h�ƃ}�E�X�̓��͂��󂯎��A�C�x���g���Ǘ�
 */
class InputManager
{
public:
	InputManager();
	~InputManager();

	/// <summary>
	/// �N���b�N�̏�Ԃ��m�F����
	/// </summary>
	/// <returns></returns>
	int CheckClickState();
	/// <summary>
	/// �R�[���o�b�N�Őݒ肳�ꂽ�֐������s
	/// </summary>
	void ExecuteCallback();
	/// <summary>
	/// �J�[�\���̃X�N���[�����W�̎擾
	/// </summary>
	/// <param name="mouseStatus"></param>
	Vector2 GetCursorScreenPos();

	inline void SetLPushCallback(std::function<void(Vector2 pos)> Callback){ _LPushAction = Callback; }
	inline void SetRPushCallback(std::function<void(Vector2 pos)> Callback){ _RPushAction = Callback; }
	inline void SetLDrackCallback(std::function<void(Vector2 pos)> Callback){ _LDrackAction = Callback; }
	inline void SetRDrackCallback(std::function<void(Vector2 pos)> Callback){ _RDrackAction = Callback; }
	inline void SetLReleaseCallback(std::function<void(Vector2 pos, Vector2 oldPos)> Callback){ _LReleaseAction = Callback; }
	inline void SetRReleaseCallback(std::function<void(Vector2 pos, Vector2 oldPos)> Callback){ _RReleaseAction = Callback; }
	inline void SetWheelRotCallback(std::function<void(Vector2 pos, int rot)> Callback){ _WheelRotAction = Callback; }
	inline void SetEscapeCallback(std::function<void()> Callback){ _EscapePushAction = Callback; }

private:
	// ���N���b�N���������Ƃ��̃R�[���o�b�N
	std::function<void(Vector2 pos)> _LPushAction;
	// �E�N���b�N���������Ƃ��̃R�[���o�b�N
	std::function<void(Vector2 pos)> _RPushAction;
	// ���N���b�N���h���b�N���Ă���Ƃ��̃R�[���o�b�N
	std::function<void(Vector2 pos)> _LDrackAction;
	// �E�N���b�N���h���b�N���Ă���Ƃ��̃R�[���o�b�N
	std::function<void(Vector2 pos)> _RDrackAction;
	// ���N���b�N�𗣂����Ƃ��̃R�[���o�b�N
	std::function<void(Vector2 pos, Vector2 oldPos)> _LReleaseAction;
	// �E�N���b�N�𗣂����Ƃ��̃R�[���o�b�N
	std::function<void(Vector2 pos, Vector2 oldPos)> _RReleaseAction;
	// �z�C�[������]�����Ƃ��̃R�[���o�b�N
	std::function<void(Vector2 pos, int rot)> _WheelRotAction;
	// Escape�L�[���������Ƃ��̃R�[���o�b�N
	std::function<void()> _EscapePushAction;
	// ���N���b�N�������ꂽ�X�N���[�����W
	Vector2 _oldLClickScreenPos;
	// �E�N���b�N�������ꂽ�X�N���[�����W
	Vector2 _oldRClickScreenPos;
	// ���N���b�N�̏��
	int _LClickState;
	// �E�N���b�N�̏��
	int _RClickState;
	// ���N���b�N��������Ă��邩
	bool _isLPressed;
	// �E�N���b�N��������Ă��邩
	bool _isRPressed;
};
