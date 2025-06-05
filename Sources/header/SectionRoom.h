#pragma once
#include "BaseSection.h"
/*
* Ishihara
* ����
*/
class SectionRoom : public BaseSection
{
public:
	SectionRoom() {}
	SectionRoom(Vector2 pos, Vector2 size, LayerSetting layerSetting) : BaseSection(pos, size, layerSetting) {
	}
	SectionRoom(Layer setLayer)
		: BaseSection(setLayer) {}
	SectionRoom(Layer setLayer, int setDrawHandle)
		: BaseSection(setLayer, setDrawHandle) {}
	SectionRoom(const SectionRoom& obj)
		: BaseSection(obj) {}
	~SectionRoom() {}

	static std::string StaticTypeName() {
		return "SectionRoom";
	}

	/// <summary>
	/// ������
	/// </summary>
	void Init(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting) override;
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

