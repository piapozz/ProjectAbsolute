#pragma once
#include<functional>

/*
 * Sakakura
 * �t�F�[�Y�̊��
 */
class BaseFase
{
public:
	inline BaseFase(){};
	inline ~BaseFase(){};

	/// <summary>
	/// ������
	/// </summary>
	inline virtual void Init() = 0;
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

	/// <summary>
	/// �I�u�W�F�N�g���Z�b�g����R�[���o�b�N
	/// </summary>
	/// <param name="callbackSetObject"></param>
	inline void SetCallbackSetObject(std::function<void()> setObjectCallback) {
		SetObject = setObjectCallback;
	}
	/// <summary>
	/// �I�u�W�F�N�g���폜����R�[���o�b�N
	/// </summary>
	/// <param name="callbackDeleteObject"></param>
	inline void SetCallbackDeleteObject(std::function<void()> deleteObjectCallback) {
		DeleteObject = deleteObjectCallback;
	}

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