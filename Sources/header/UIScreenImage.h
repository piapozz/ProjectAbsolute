#pragma once
#include "BaseUIScreen.h"
class UIScreenImage:
    public BaseUIScreen
{
public:
	UIScreenImage() {
	}
	UIScreenImage(Vector2 setPosition, Vector2 setSize, bool fill, LayerSetting layerSetting) {
		Init(setPosition, setSize, fill, layerSetting);
	}
	UIScreenImage(Layer setLayer)
		: BaseUIScreen(setLayer) {
	}
	UIScreenImage(Layer setLayer, int setDrawHandle)
		: BaseUIScreen(setLayer, setDrawHandle) {
	}
	UIScreenImage(const BaseUIScreen& obj)
		: BaseUIScreen(obj) {
	}
	~UIScreenImage() {
	}

	void Init(Vector2 setPosition, Vector2 setSize, bool fill, LayerSetting layerSetting);
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	void OnCursor();
	void NotOnCursor();
	static std::string StaticTypeName() {
		return "UIScreenImage";
	}
	void DrawUIBox(int color = NULL);
private:
	bool _fill;
	int _outLineColor;
};

