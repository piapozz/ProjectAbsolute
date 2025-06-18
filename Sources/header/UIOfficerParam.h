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

	void SetParamName(std::string str);
	void SetParam(float value);
private:
	// 背景
	UIScreenImage* _pBackground;
	// パラメーター名
	UIScreenText* _pParamName;
	// パラメーター値
	UIScreenText* _pParamValue;

	// 座標,サイズ(相対割合)

	// 背景
	const Vector2 BACKGROUND_SIZE = Vector2(1, 1);
	const Vector2 BACKGROUND_POS =  Vector2(0, 0);
	// パラメーター名
	const Vector2 NAME_SIZE = Vector2(0.5f, 1);
	const Vector2 NAME_POS =  Vector2(-0.25f, 0);
	// パラメーター値
	const Vector2 VALUE_SIZE = Vector2(0.5f, 1);
	const Vector2 VALUE_POS =  Vector2(0.25f, 0);
};

