#pragma once
#include "BaseUI.h"
/*
* ishihara
* UIテキスト
*/
class UIText : public BaseUI
{
public:
	UIText() {
	}
	UIText(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting) {
		Init(setPosition, setSize, layerSetting);
	}
	UIText(Layer setLayer)
		: BaseUI(setLayer) {
	}
	UIText(Layer setLayer, int setDrawHandle)
		: BaseUI(setLayer, setDrawHandle) {
	}
	UIText(const UIText& obj)
		: BaseUI(obj) {
	}
	~UIText() {
	}
	void Init(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;

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

	static std::string StaticTypeName() {
		return "UIText";
	}

private:
	std::string text;
	int textGraph;
	int textSize;
	int fontHandle;

	// 文字
	std::string prevText = "";
};