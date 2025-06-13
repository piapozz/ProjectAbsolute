#pragma once
#include "../header/BaseUIScreen.h"

/*
* ishihara
* UIスクリーンテキスト
*/
class UIScreenText : public BaseUIScreen
{
public:
	UIScreenText() {
	}
	UIScreenText(Transform setTransform, LayerSetting layerSetting) {
		Init(setTransform, layerSetting);
	}
	UIScreenText(Layer setLayer)
		: BaseUIScreen(setLayer) {
	}
	UIScreenText(Layer setLayer, int setDrawHandle)
		: BaseUIScreen(setLayer, setDrawHandle) {
	}
	UIScreenText(const UIScreenText& obj)
		: BaseUIScreen(obj) {
	}
	~UIScreenText() {
	}
	void Init(Transform setTransform, LayerSetting layerSetting);
	void Proc() override;
	void Draw() override;
	void Teardown() override;


	void SetTextColor(int r = 255, int g = 255, int b = 255){
		_textColor = GetColor(r, g, b);
	}
	void SetText(const std::string& setText){
		_text = setText;
	}

	static std::string StaticTypeName() {
		return "UIScreenText";
	}

	void DrawUIText();
private:
	int textGraph;
	int textSize;
	int fontHandle;
	std::string _text;
	int _textColor;
};
