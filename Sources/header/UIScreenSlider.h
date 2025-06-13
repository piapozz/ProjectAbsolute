#pragma once
#include "UIScreenImage.h"
#include "UIScreenText.h"
/*
* ishihara
* UIスクリーンスライダー
*/
class UIScreenSlider : public BaseUIScreen
{
public:
	UIScreenSlider() {}
	UIScreenSlider(Transform setTransform, bool fill, LayerSetting layerSetting) {
		Init(setTransform, fill, layerSetting);
	}
	UIScreenSlider(Layer setLayer): BaseUIScreen(setLayer) {}
	UIScreenSlider(Layer setLayer, int setDrawHandle): BaseUIScreen(setLayer, setDrawHandle) {}
	UIScreenSlider(const UIScreenSlider& obj): BaseUIScreen(obj) {}
	~UIScreenSlider() {}
	void Init(Transform setTransform, bool fill, LayerSetting layerSetting);
	void Proc() override;
	void Draw() override;
	void Teardown() override;

	static std::string StaticTypeName() {
		return "UIScreenSlider";
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
	void SetColor(int r = 255, int g = 255, int b = 255) {
		_color = GetColor(r, g, b);
	}

	void SetText(const std::string& setText) {
		_pText->SetText(setText);
	}

	void SetTextColor(int r = 255, int g = 255, int b = 255) {
		_pText->SetTextColor(r, g, b);
	}

	void SetActive(bool active) override {
		BaseObject::SetActive(active);
		_pImage->SetActive(active);
		_pText->SetActive(active);
	}

private:
	UIScreenImage* _pImage;
	UIScreenText* _pText;
	// スライダーの値
	float _value;
	// スライダーの色
	int _color;
};
