#pragma once
#include "BaseObject.h"
class BaseUIScreen:public BaseObject
{
public:
	BaseUIScreen() {
	}
	BaseUIScreen(Layer setLayer)
		: BaseObject(setLayer) {
	}
	BaseUIScreen(Layer setLayer, int setDrawHandle)
		: BaseObject(setLayer, setDrawHandle) {
	}
	BaseUIScreen(const BaseUIScreen& obj)
		: BaseObject(obj) {
	}
	~BaseUIScreen() {}

	void Init(Vector2 setPosition, Vector2 setSize);
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	void SetTextColor(int r = 255, int g = 255, int b = 255){ _textColor = GetColor(r, g, b); }
	void SetText(const std::string& setText){ _text = setText; }
	void OnCursor() override;
protected:
	void DrawUIBox(int color = NULL);
	void DrawUIText();
	std::string text;
	int textGraph;
	int textSize;
	int fontHandle;
private:
	Vector2 _screenPos;
	std::string _text;
	int _textColor;
};

