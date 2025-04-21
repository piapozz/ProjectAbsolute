#pragma once
#include "BaseSection.h"
/*
* Ishihara
* �ڍ���
*/
class SectionConnect: public BaseSection
{
public:
	SectionConnect() {
	}
	SectionConnect(Layer setLayer)
		: BaseSection(setLayer) {
	}
	SectionConnect(Layer setLayer, int setDrawHandle)
		: BaseSection(setLayer, setDrawHandle) {
	}
	SectionConnect(const SectionConnect& obj)
		: BaseSection(obj) {
	}
	~SectionConnect() {
	}

	/// <summary>
	/// ������
	/// </summary>
	void Init(Vector2 setPosition, Vector2 setSize) override;
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

