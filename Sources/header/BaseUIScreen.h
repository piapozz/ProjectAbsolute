#pragma once
#include "BaseUI.h"
class BaseUIScreen:public BaseUI
{
public:
	BaseUIScreen() {
	}
	BaseUIScreen(Layer setLayer)
		: BaseUI(setLayer) {
	}
	BaseUIScreen(Layer setLayer, int setDrawHandle)
		: BaseUI(setLayer, setDrawHandle) {
	}
	BaseUIScreen(const BaseUI& obj)
		: BaseUI(obj) {
	}
	~BaseUIScreen() {}

	void Init(Vector2 setPosition, Vector2 setSize) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	void SetTextColor(int r = 255, int g = 255, int b = 255){ _textColor = GetColor(r, g, b); }
	void SetText(const char* setText){ _text = setText; }
protected:
	void DrawUIBox();
	void DrawUIText();
private:
	// スクリーン座標
	Vector2 _screenPos;
	const char* _text;
	int _textColor;
};

