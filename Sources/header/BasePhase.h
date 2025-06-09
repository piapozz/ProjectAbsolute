#pragma once
#include<functional>
#include "ObjectManager.h"
class InputManager;
/*
 * Sakakura
 * �t�F�[�Y�̊��
 */
class BasePhase
{
public:
	inline BasePhase(){};
	inline ~BasePhase(){};

	/// <summary>
	/// ������
	/// </summary>
	inline virtual void Init(){};
	/// <summary>
	/// �j��
	/// </summary>
	inline virtual void Teardown(){ ObjectManager::Instance().AllClear(); }
	/// <summary>
	/// �V�[����؂�ւ���R�[���o�b�N��ݒ肷��
	/// </summary>
	/// <param name="callback"></param>
	inline void SetChangePhaseCallback(std::function<void(PhaseName nextPhase)> callback){ ChangePhase = callback; }

protected:
	/// <summary>
	/// �J�[�\��������Ă���Ƃ��̏���
	/// </summary>
	/// <param name="pos"></param>
	virtual void OnCursorProc(Vector2 pos){}
	/// <summary>
	/// ���N���b�N���������Ƃ��̏���
	/// </summary>
	/// <param name="pos"></param>
	virtual void LPushInputProc(Vector2 pos){}
	/// <summary>
	/// �E�N���b�N���������Ƃ��̏���
	/// </summary>
	/// <param name="pos"></param>
	virtual void RPushInputProc(Vector2 pos){}
	/// <summary>
	/// ���N���b�N���h���b�N���Ă���Ƃ��̏���
	/// </summary>
	/// <param name="pos"></param>
	virtual void LDrackInputProc(Vector2 pos, Vector2 oldPos){}
	/// <summary>
	/// �E�N���b�N���h���b�N���Ă���Ƃ��̏���
	/// </summary>
	/// <param name="pos"></param>
	virtual void RDrackInputProc(Vector2 pos, Vector2 oldPos){}
	/// <summary>
	/// ���N���b�N�𗣂����Ƃ��̏���
	/// </summary>
	/// <param name="pos"></param>
	/// <param name="oldPos"></param>
	virtual void LReleaseInputProc(Vector2 pos, Vector2 oldPos){}
	/// <summary>
	/// �E�N���b�N�𗣂����Ƃ��̏���
	/// </summary>
	/// <param name="pos"></param>
	/// <param name="oldPos"></param>
	virtual void RReleaseInputProc(Vector2 pos, Vector2 oldPos){}
	/// <summary>
	/// �z�C�[������]�����Ƃ��̏���
	/// </summary>
	virtual void WheelRotInputProc(Vector2 pos, int rot){};
	/// <summary>
	/// Escape�L�[���������Ƃ��̏���
	/// </summary>
	virtual void EscapeInputProc(){};

	std::function<void(PhaseName nextPhase)> ChangePhase;
};