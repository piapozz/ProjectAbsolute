#pragma once
#include "BaseUI.h"
class UIImage:
    public BaseUI
{
public:
	UIImage() {
	}
	UIImage(Transform setTransform, LayerSetting layerSetting) {
		Init(setTransform, layerSetting);
	}
	UIImage(Layer setLayer)
		: BaseUI(setLayer) {
	}
	UIImage(Layer setLayer, int setDrawHandle)
		: BaseUI(setLayer, setDrawHandle) {
	}
	UIImage(const UIImage& obj)
		: BaseUI(obj) {
	}
	~UIImage() {
	}
	void Init(Transform setTransform, LayerSetting layerSetting) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	static std::string StaticTypeName() {
		return "UIImage";
	}

	void OnCursor() override {
	};
	void NotOnCursor() override {
	};
};

