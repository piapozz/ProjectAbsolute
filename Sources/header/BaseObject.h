#pragma once
#include "../header/CommonModule.h"
#include "../header/Const.h"
#include "../header/AutoTypeNameObject.h"
/*
* Ishihara
* オブジェクトの基底
*/
class BaseObject : public AutoTypeNameObject
{
public:
	BaseObject(){
		objectType = ObjectType::INVALID;
	 }
	BaseObject(Vector2 pos, Vector2 size, Layer setLayer)
		: position(pos), objectSize(size), layer(setLayer) {
		objectType = ObjectType::INVALID;
		drawHandle = -1;
	}
	BaseObject(Vector2 pos, Vector2 size, LayerSetting layerSetting)
		: position(pos), objectSize(size), active(layerSetting.m_active), 
		interactable(layerSetting.m_interact), layer(layerSetting.m_layer) {
		objectType = ObjectType::INVALID;
		drawHandle = -1;
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
	virtual void Proc(){}
	/// <summary>
	/// 描画
	/// </summary>
	virtual void Draw(){}
	/// <summary>
	/// 破棄
	/// </summary>
	virtual void Teardown();
	virtual void ClickEvent(){}
	virtual void OnCursor(){}
	virtual void NotOnCursor(){}

	static std::string StaticTypeName() {
		return "BaseObject";
	}

	inline Vector2 GetPosition(){ return position; }
	inline Layer GetLayer() { return layer; }
	inline ObjectType GetType() { return objectType; }
	inline bool GetActive() { return active; }
	inline bool GetInteract() { return interactable; }
	inline void SetPosition(Vector2 setPosition){ position = setPosition; }
	inline void SetSize(Vector2 setSize){ objectSize = setSize; }
	inline void SetActive(bool setActive){ active = setActive; }
	inline void SetInteract(bool setInteract){ interactable = setInteract; }

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
protected:
	// アクティブ状態
	bool active;
	// インタラクト可能か
	bool interactable;
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