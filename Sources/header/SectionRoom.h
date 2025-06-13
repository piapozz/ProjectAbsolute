#pragma once
#include "BaseSection.h"
/*
* Ishihara
* 部屋
*/
class SectionRoom : public BaseSection
{
public:
	SectionRoom() {}
	SectionRoom(Transform setTransform, LayerSetting layerSetting) : BaseSection(setTransform, layerSetting) {
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
	/// 初期化
	/// </summary>
	void Init(Transform setTransform, LayerSetting layerSetting) override;
	/// <summary>
	/// アップデート
	/// </summary>
	void Proc() override;
	/// <summary>
	/// 描画
	/// </summary>
	void Draw() override;
	/// <summary>
	/// 破棄
	/// </summary>
	void Teardown() override;
};

