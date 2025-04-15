#pragma once
#include<functional>
#include "ObjectManager.h"

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
	// �I�u�W�F�N�g���Z�b�g����R�[���o�b�N
	std::function<void()> SetObject;
	// �I�u�W�F�N�g��j������R�[���o�b�N
	std::function<void()> DeleteObject;

	/// <summary>
	/// ���͂ɉ���������
	/// </summary>
	virtual void InputProc() = 0;
};