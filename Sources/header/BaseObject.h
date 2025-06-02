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
	BaseObject(){
		objectType = ObjectType::INVALID;
	 }
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
	virtual void Proc(){};
	/// <summary>
	/// 描画
	/// </summary>
	virtual void Draw(){
	};
	/// <summary>
	/// 破棄
	/// </summary>
	virtual void Teardown();
	virtual void ClickEvent(){
	};

	inline void SetLayer(Layer setLayer) { layer = setLayer; }
	inline Layer GetLayer() { return layer; }
	inline ObjectType GetType() { return objectType; }
	/// <summary>
	/// オブジェクトが重なっているかどうか
	/// </summary>
	/// <param name="pos"></param>
	/// <returns></returns>
	bool IsSamePos(Vector2 pos);
	/// <summary>
	/// オブジェクトが範囲内かどうか
	/// </summary>
	/// <param name="pos"></param>
	/// <param name="size"></param>
	/// <returns></returns>
	bool IsSameRect(Vector2 pos, Vector2 size);
	/// <summary>
	/// 表示の切り替え
	/// </summary>
	/// <param name="active"></param>
	void SetActive(bool active);
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