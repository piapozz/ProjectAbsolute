#pragma once
#include "Const.h"
#include "DxLib.h"
#include "functional"
/*
* Ishihara
* �V�[���̊��
*/
class BaseScene 
{
protected:
	// �R�[���o�b�N
	std::function<void(SceneName)> ChangeScene;
public:
	BaseScene(){}
	virtual ~BaseScene(){}

	/// <summary>
	/// �V�[���ύX�R�[���o�b�N�ݒ�
	/// </summary>
	/// <param name="setCallback"></param>
	void SetCallback(const std::function<void(SceneName)>& setCallback){ ChangeScene = setCallback; }
	/// <summary>
	/// ������
	/// </summary>
	virtual void Init() = 0;
	/// <summary>
	/// ����
	/// </summary>
	virtual void Proc() = 0;
	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw() = 0;
};
