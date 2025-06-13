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
	BaseUI(Transform setTransform, LayerSetting layerSetting) {
		Init(setTransform, layerSetting);
	}
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
	/// 座標の変更
	/// </summary>
	/// <param name="setPos"></param>
	void SetPos(Vector2 setPos) {
		transform.position = setPos;
	}
};

