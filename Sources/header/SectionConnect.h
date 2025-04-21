#pragma once
#include "BaseSection.h"
/*
* Ishihara
* 接合部
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

