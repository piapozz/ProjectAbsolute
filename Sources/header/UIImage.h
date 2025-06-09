#pragma once
#include "BaseUI.h"
class UIImage:
    public BaseUI
{
public:
	UIImage() {
	}
	UIImage(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting) {
		Init(setPosition, setSize, layerSetting);
	}
	UIImage(UISetting setting, LayerSetting layerSetting) {
		Init(setting.m_position, setting.m_size, layerSetting);
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
	void Init(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting) override;
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

