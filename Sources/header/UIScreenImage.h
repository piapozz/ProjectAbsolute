#pragma once
#include "BaseUIScreen.h"
class UIScreenImage:
    public BaseUIScreen
{
public:
	static std::string StaticTypeName() {
		return "UIScreenImage";
	}
	UIScreenImage() {
	}
	UIScreenImage(Transform setTransform, bool fill, LayerSetting layerSetting) {
		Init(setTransform, fill, layerSetting);
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

	void Init(Transform setTransform, bool fill, LayerSetting layerSetting);
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	void OnCursor();
	void NotOnCursor();
	void DrawUIBox();
	inline void SetColor(int color){ _color = color; }
	inline void SetOutLineColor(int color){ _outLineColor = color; }
private:
	bool _fill;
	bool _onCorsor;
	int _color;
	int _outLineColor;
};

