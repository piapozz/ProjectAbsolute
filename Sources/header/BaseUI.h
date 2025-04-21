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
	/// 表示の切り替え
	/// </summary>
	/// <param name="active"></param>
	void SetActive(bool active);
	/// <summary>
	/// 画面に追従させるかどうか
	/// </summary>
	/// <param name="is2D"></param>
	void Set2D(bool is2D) { _is2D = is2D; }
protected:
	int fontHandle;
	int textGraph;;
private:
	// "2Dか3Dか
	bool _is2D;
};

