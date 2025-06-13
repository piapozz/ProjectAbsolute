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
	SectionConnect(Transform setTransform, LayerSetting layerSetting): BaseSection(setTransform, layerSetting) {
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

	static std::string StaticTypeName() {
		return "SectionConnect";
	}

	/// <summary>
	/// ������
	/// </summary>
	void Init(Transform setTransform, LayerSetting layerSetting) override;
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

