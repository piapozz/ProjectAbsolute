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
	SectionRoom(Vector2 pos, Vector2 size) : BaseSection(pos,size) {
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

	std::string GetTypeName() const override {
		return StaticTypeName();
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

