#pragma once
#include "UIScreen.h"

class UIOfficerParam : public BaseUIScreen
{
public:
	UIOfficerParam() {}
	UIOfficerParam(Transform setTransform, bool fill, LayerSetting layerSetting) {
		Init(setTransform, fill, layerSetting);
	}
	UIOfficerParam(Layer setLayer)
		: BaseUIScreen(setLayer) {}
	UIOfficerParam(Layer setLayer, int setDrawHandle)
		: BaseUIScreen(setLayer, setDrawHandle) {}
	UIOfficerParam(const UIOfficerParam& obj)
		: BaseUIScreen(obj) {}
	~UIOfficerParam() {}
	void Init(Transform setTransform, bool fill, LayerSetting layerSetting);
	void Proc() override;
	void Draw() override;
	void Teardown() override;
private:
	// 背景
	UIScreenImage* _pBackground;
	// パラメーター名
	UIScreenText* _pParamName;
	// パラメーター値
	UIScreenText* _pParamValue;
};

