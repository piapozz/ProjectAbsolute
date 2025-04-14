#pragma once
#include "BaseObject.h"
/*
* Ishihara
* UI基底
*/
class BaseUI: public BaseObject
{
public:
	BaseUI() {}
	BaseUI(Layer setLayer)
		: BaseObject(setLayer) {}
	BaseUI(Layer setLayer,int setDrawHandle)
		: BaseObject(setLayer,setDrawHandle) {}
	BaseUI(const BaseUI& obj)
		: BaseObject(obj) {}
	~BaseUI() {}

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

