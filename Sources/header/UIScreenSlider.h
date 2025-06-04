#pragma once
#include "../header/BaseUIScreen.h"
/*
* ishihara
* UIスクリーンスライダー
*/
class UIScreenSlider : public BaseUIScreen
{
public:
	UIScreenSlider() {}
	UIScreenSlider(Layer setLayer): BaseUIScreen(setLayer) {}
	UIScreenSlider(Layer setLayer, int setDrawHandle): BaseUIScreen(setLayer, setDrawHandle) {}
	UIScreenSlider(const UIScreenSlider& obj): BaseUIScreen(obj) {}
	~UIScreenSlider() {}
	void Init(Vector2 setPosition, Vector2 setSize, bool fill);
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
	void SetColor(int r = 255, int g = 255, int b = 255) {
		_color = GetColor(r, g, b);
	}
private:
	// スライダーの値
	float _value;
	// スライダーの色
	int _color;
};
