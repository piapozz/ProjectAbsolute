#pragma once
#include "BaseObject.h"
/*
* Ishihara
* 部屋の基底
*/
class BaseSection: public BaseObject
{
public:
	BaseSection() {}
	BaseSection(Layer setLayer)
		: BaseObject(setLayer) {}
	BaseSection(Layer setLayer,int setDrawHandle)
		: BaseObject(setLayer,setDrawHandle) {}
	BaseSection(const BaseSection& obj)
		: BaseObject(obj) {}
	~BaseSection() {}

	/// <summary>
	/// 初期化
	/// </summary>
	void Init() override;
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

