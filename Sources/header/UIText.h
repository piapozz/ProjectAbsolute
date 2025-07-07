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
	UIText(Transform setTransform, LayerSetting layerSetting) {
		Init(setTransform, layerSetting);
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
	void Init(Transform setTransform, LayerSetting layerSetting) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;

	/// <summary>
	/// 大きさの変更
	/// </summary>
	/// <param name="setSize"></param>
	inline void SetFontSize(int setSize){ fontSize = setSize; }
	/// <summary>
	/// テキストの設定
	/// </summary>
	/// <param name="text"></param>
	void SetText(const std::string& setText) {
		text = setText;
	}

	static std::string StaticTypeName() {
		return "UIText";
	}

private:
	std::string text;
	int textGraph;
	int textSize;
	int fontSize;

	// 文字
	std::string prevText = "";

	const int _DEFAULT_FONT_SIZE = 24;
};