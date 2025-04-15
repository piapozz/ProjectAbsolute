#pragma once
#include "BaseObject.h"
/*
* Ishihara
* �����̊��
*/
class BaseSection: public BaseObject
{
public:
	BaseSection(): BaseObject() { }
	BaseSection(Layer setLayer)
		: BaseObject(setLayer) {}
	BaseSection(Layer setLayer, int setDrawHandle)
		: BaseObject(setLayer, setDrawHandle) {}
	BaseSection(const BaseSection& obj)
		: BaseObject(obj) {}
	~BaseSection() {}

	/// <summary>
	/// ������
	/// </summary>
 	virtual void Init(Vector2 setPosition, int setSize);
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
protected:
	// �������ǂ̕����̃^�C�v��
	SectionType sectionType;
	// �ڑ���
	bool isConnect[static_cast<int>(Direction::MAX)];
	// �T�C�Y
	int size;
};

