#pragma once  
#include "BaseUI.h"	

class UISlider: public BaseUI
{
public:
	UISlider() {}
	UISlider(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting){
		Init(setPosition, setSize, layerSetting);
	}
	UISlider(UISetting setting, LayerSetting layerSetting) {
		Init(setting.m_position, setting.m_size, layerSetting);
		SetSize(setting.m_size.x);
		SetText(setting.m_text);
	}
	UISlider(Layer setLayer)
		: BaseUI(setLayer) {}
	UISlider(Layer setLayer, int setDrawHandle)
		: BaseUI(setLayer, setDrawHandle) {}
	UISlider(const UISlider& obj)
		: BaseUI(obj) {}
	~UISlider() {}

	void Init(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;

	static std::string StaticTypeName() {
		return "UISlider";
	}

	/// <summary>
	/// 値の設定
	/// </summary>
	/// <param name="value"></param>
	void SetValue(float value) {
		_value = value;
	}
	/// <summary>
	/// 色の設定
	/// </summary>
	void SetColor(int r = 255, int g = 255, int b = 255, int a = 255) {
		color = GetColorU8(r, g, b, a);
	}
private:
	// スライダーの値
	float _value;
	// スライダーの色
	COLOR_U8 color;
};

