#pragma once
#include "BaseSection.h"
/*
* Ishihara
* 廊下
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
	/// 初期化
	/// </summary>
	void Init(Vector2 setPosition, Vector2 setSize) override;
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

