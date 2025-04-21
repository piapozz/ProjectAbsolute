#pragma once  
#include "BaseUI.h"	

class UISlider: public BaseUI
{
public:
	UISlider() {}
	UISlider(Layer setLayer)
		: BaseUI(setLayer) {}
	UISlider(Layer setLayer, int setDrawHandle)
		: BaseUI(setLayer, setDrawHandle) {}
	UISlider(const UISlider& obj)
		: BaseUI(obj) {}
	~UISlider() {}

	void Init(Vector2 setPosition, Vector2 setSize) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;

private:
	// スライダーの値
	float _value;
};

