#pragma once
#include "CommonModule.h"
#include "DxLib.h"
/*
* Ishihara
* オブジェクトの基底
*/
class BaseObject
{
public:
	BaseObject(){}
	BaseObject(int setLayer) 
		: layer(setLayer){}
	BaseObject(int setLayer, int setDrawHandle) 
		: layer(setLayer),drawHandle(setDrawHandle){}
	BaseObject(const BaseObject& obj)
		: layer(obj.layer),drawHandle(obj.drawHandle){}
	~BaseObject(){ }

	/// <summary>
	/// 初期化
	/// </summary>
	virtual void Init(){};
	/// <summary>
	/// アップデート
	/// </summary>
	virtual void Proc(){};
	/// <summary>
	/// 描画
	/// </summary>
	virtual void Draw(){};
	/// <summary>
	/// 破棄
	/// </summary>
	virtual void Teardown();

	inline void SetLayer(int setLayer) { layer = setLayer;}
	inline int GetLayer() { return layer; }
protected:
	// レイヤー
	int layer;
	// 描画用のハンドル
	int drawHandle;
	// 座標
	Vector2 position;
};