#pragma once
#include "BaseUI.h"
/*
* ishihara
* UIスクリーンスライダー
*/
class UIScreenSlider : public BaseUI
{
public:
	UIScreenSlider() {
	}
	UIScreenSlider(Layer setLayer)
		: BaseUI(setLayer) {
	}
	UIScreenSlider(Layer setLayer, int setDrawHandle)
		: BaseUI(setLayer, setDrawHandle) {
	}
	UIScreenSlider(const UIScreenSlider& obj)
		: BaseUI(obj) {
	}
	~UIScreenSlider() {
	}
	void Init(Vector2 setPosition, Vector2 setSize) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;
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
