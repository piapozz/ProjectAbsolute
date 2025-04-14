#pragma once
#include "BaseObject.h"
/*
* Ishihara
* �����̊��
*/
class BaseSection: public BaseObject
{
public:
	BaseSection() {}
	BaseSection(Layer setLayer)
		: BaseObject(setLayer) {}
	BaseSection(Layer setLayer,int setDrawHandle)
		: BaseObject(setLayer,setDrawHandle) {}
	BaseSection(const BaseSection& obj)
		: BaseObject(obj) {}
	~BaseSection() {}

	/// <summary>
	/// ������
	/// </summary>
	void Init() override;
	/// <summary>
	/// �A�b�v�f�[�g
	/// </summary>
	void Proc() override;
	/// <summary>
	/// �`��
	/// </summary>
	void Draw() override;
	/// <summary>
	/// �j��
	/// </summary>
	void Teardown() override;
};

