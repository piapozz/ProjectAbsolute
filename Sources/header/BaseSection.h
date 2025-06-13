#pragma once
#include "BaseObject.h"

class BaseCharacter;
/*
* Ishihara
* 部屋の基底
*/
class BaseSection: public BaseObject
{
public:
	BaseSection(): BaseObject() { }
	BaseSection(Transform setTransform, LayerSetting layerSetting){
		Init(setTransform, layerSetting);
	}
	BaseSection(Layer setLayer)
		: BaseObject(setLayer) {}
	BaseSection(Layer setLayer, int setDrawHandle)
		: BaseObject(setLayer, setDrawHandle) {}
	BaseSection(const BaseSection& obj)
		: BaseObject(obj) {}
	~BaseSection() {}

	/// <summary>
	/// 初期化
	/// </summary>
 	virtual void Init(Transform setTransform, LayerSetting layerSetting);
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
	/// <summary>
	/// クリックしたときのイベント
	/// </summary>
	void ClickEvent() override;
	/// <summary>
	/// キャラクターの取得
	/// </summary>
	/// <returns></returns>
	std::vector<BaseCharacter*> GetCharacters();
protected:
	// 自分がどの部屋のタイプか
	SectionType sectionType;
	// 接続数
	bool isConnect[static_cast<int>(DirFour::MAX)];
};

