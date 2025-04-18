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
	/// �N���b�N���ꂽ�����擾
	/// </summary>
	/// <param name="button"></param>
	/// <param name="isPush"></param>
	/// <returns></returns>
	bool IsClick(int button);
	/// <summary>
	/// �R�[���o�b�N�Őݒ肳�ꂽ�֐������s
	/// </summary>
	void ExecuteCallback();
	/// <summary>
	/// �J�[�\���̃X�N���[�����W�̎擾
	/// </summary>
	/// <param name="mouseStatus"></param>
	Vector2 GetCursorScreenPos();
	/// <summary>
	/// �J�[�\���̃X�N���[�����W���烏�[���h���W�̎擾
	/// </summary>
	/// <returns></returns>
	Vector2 GetCursorWorldPos(Vector2 screenPos);

	inline void SetLPushCallback(std::function<void(Vector2 pos)> Callback){ _LPushAction = Callback; }
	inline void SetRPushCallback(std::function<void(Vector2 pos)> Callback){ _RPushAction = Callback; }
	inline void SetLReleaseCallback(std::function<void(Vector2 pos, Vector2 oldPos)> Callback){ _LReleaseAction = Callback; }
	inline void SetRReleaseCallback(std::function<void(Vector2 pos, Vector2 oldPos)> Callback){ _RReleaseAction = Callback; }
	inline void SetWheelRotCallback(std::function<void(Vector2 pos, int rot)> Callback){ _WheelRotAction = Callback; }
	inline void SetEscapeCallback(std::function<void()> Callback){ _EscapePushAction = Callback; }

private:
	// ���N���b�N���������Ƃ��̃R�[���o�b�N
	std::function<void(Vector2 pos)> _LPushAction;
	// �E�N���b�N���������Ƃ��̃R�[���o�b�N
	std::function<void(Vector2 pos)> _RPushAction;
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
};
