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
	inline virtual void Init() { ObjectManager::Init();};
	/// <summary>
	//// �����̃��[�v
	// </summary>
	void ProcLoop();
	/// <summary>
	/// ����
	/// </summary>
	/// <returns>�I���������ۂ�</returns>
	inline virtual bool Proc() = 0;
	/// <summary>
	/// �j��
	/// </summary>
	inline virtual void Teardown() = 0;

protected:
	/// <summary>
	/// ���N���b�N�����Ƃ��̏���
	/// </summary>
	virtual void LClickInputProc(Vector2 pos, Vector2 oldPos){};
	/// <summary>
	/// �E�N���b�N�����Ƃ��̏���
	/// </summary>
	virtual void RClickInputProc(Vector2 pos, Vector2 oldPos){};
	/// <summary>
	/// �z�C�[������]�����Ƃ��̏���
	/// </summary>
	virtual void WheelRotInputProc(Vector2 pos, int rot){};
	/// <summary>
	/// Escape�L�[���������Ƃ��̏���
	/// </summary>
	virtual void EscapeInputProc(){};

	InputManager* pInputManager;
};