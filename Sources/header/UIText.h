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

	static std::string StaticTypeName() {
		return "UIText";
	}

private:
};