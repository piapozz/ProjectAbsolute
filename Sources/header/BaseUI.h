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
	/// 座標の変更
	/// </summary>
	/// <param name="setPos"></param>
	void SetPos(Vector2 setPos) {
		position = setPos;
	}
	/// <summary>
	/// 大きさの変更
	/// </summary>
	/// <param name="setSize"></param>
	void SetSize(int setSize){
		textSize = setSize;
	}
	/// <summary>
	/// テキストの設定
	/// </summary>
	/// <param name="text"></param>
	void SetText(const std::string& setText) {
		text = setText;
	}
	/// <summary>
	/// フォントの設定
	/// </summary>
	/// <param name="setFont"></param>
	/// <param name="size"></param>
	/// <param name="thick"></param>
	void SetFontHandle(const char* setFont, int size, int thick){
		fontHandle = CreateFontToHandle(setFont, size, thick, DX_FONTTYPE_ANTIALIASING);
	}
protected:
	std::string text;
	int textGraph;
	int textSize;
	int fontHandle;
private:
	// 文字
	std::string prevText = "";
};

