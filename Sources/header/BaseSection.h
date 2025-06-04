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
	BaseSection(Vector2 pos, Vector2 size){
		Init(pos, size);
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
 	virtual void Init(Vector2 setPosition, Vector2 setSize);
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
	/// キャラクターの取得
	/// </summary>
	/// <returns></returns>
	std::vector<BaseCharacter*> GetCharacters() const;
protected:
	// 自分がどの部屋のタイプか
	SectionType sectionType;
	// 接続数
	bool isConnect[static_cast<int>(DirFour::MAX)];
};

