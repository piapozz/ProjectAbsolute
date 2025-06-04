#pragma once
#include "BaseSection.h"
/*
* Ishihara
* �L��
*/
class SectionCorridor: public BaseSection
{
public:
	SectionCorridor() {
	}
	SectionCorridor(Vector2 pos, Vector2 size): BaseSection(pos, size) {
	}
	SectionCorridor(Layer setLayer)
		: BaseSection(setLayer) {
	}
	SectionCorridor(Layer setLayer, int setDrawHandle)
		: BaseSection(setLayer, setDrawHandle) {
	}
	SectionCorridor(const SectionCorridor& obj)
		: BaseSection(obj) {
	}
	~SectionCorridor() {
	}

	static std::string StaticTypeName() {
		return "SectionCorridor";
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

