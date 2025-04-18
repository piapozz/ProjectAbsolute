#pragma once
#include "../header/CommonModule.h"
#include "../header/Const.h"
/*
* Ishihara
* オブジェクトの基底
*/
class BaseObject
{
public:
	BaseObject(){}
	BaseObject(Layer setLayer)
		: layer(setLayer){}
	BaseObject(Layer setLayer, int setDrawHandle)
		: layer(setLayer),drawHandle(setDrawHandle){}
	BaseObject(const BaseObject& obj)
		: layer(obj.layer),drawHandle(obj.drawHandle){}
	~BaseObject(){ }

	/// <summary>
	/// アップデート
	/// </summary>
	virtual void Proc() = 0;
	/// <summary>
	/// 描画
	/// </summary>
	virtual void Draw() = 0;
	/// <summary>
	/// 破棄
	/// </summary>
	virtual void Teardown();
	virtual void ClickEvent() = 0;

	inline void SetLayer(Layer setLayer) { layer = setLayer; }
	inline Layer GetLayer() { return layer; }
	inline ObjectType GetType() { return objectType; }
	inline bool IsSamePos(Vector2 pos);
protected:
	// レイヤー
	Layer layer;
	// 描画用のハンドル
	int drawHandle;
	// 座標
	Vector2 position;
	// どのタイプか
	ObjectType objectType;
	// サイズ
	Vector2 objectSize;
};