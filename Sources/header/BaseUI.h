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
		_textSize = setSize;
	}
	/// <summary>
	/// テキストの設定
	/// </summary>
	/// <param name="text"></param>
	void SetText(const std::string& text) {
		_text = text;
	}
private:
	int _fontHandle;
	int _textGraph;
	int _textSize;
	// ボタンの文字
	std::string _text;
	std::string prevText = "";
};

