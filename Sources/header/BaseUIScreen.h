#pragma once
#include "BaseObject.h"
class BaseUIScreen:public BaseObject
{
public:
	BaseUIScreen() {
	}
	BaseUIScreen(Transform setTransform, LayerSetting layerSetting) {
		Init(setTransform, layerSetting);
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

	void Init(Transform setTrasnform, LayerSetting layerSetting);
	void Proc() override;
	void Draw() override;
	void Teardown() override;
};

