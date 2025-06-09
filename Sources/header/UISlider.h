#pragma once  
#include "BaseUI.h"	
#include "UIText.h"
#include "UIImage.h"

class UISlider: public BaseUI
{
public:
	UISlider() {}
	UISlider(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting){
		Init(setPosition, setSize, layerSetting);
	}
	UISlider(UISetting setting, LayerSetting layerSetting) {
		Init(setting.m_position, setting.m_size, layerSetting);
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

	void SetText(const std::string setText) {
		_pText->SetText(setText);
	}

	void SetActive(bool active) override {
		BaseObject::SetActive(active);
		_pImage->SetActive(active);
		_pText->SetActive(active);
	}

private:
	// テキスト
	UIText* _pText;
	// 画像
	UIImage* _pImage;
	// スライダーの値
	float _value;
	// スライダーの色
	COLOR_U8 color;
};

