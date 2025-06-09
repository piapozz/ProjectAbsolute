#pragma once
#include "BaseObject.h"
class BaseUIScreen:public BaseObject
{
public:
	BaseUIScreen() {
	}
	BaseUIScreen(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting) {
		Init(setPosition, setSize, layerSetting);
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

	void Init(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting);
	void Proc() override;
	void Draw() override;
	void Teardown() override;
private:
	Vector2 _screenPos;
};

