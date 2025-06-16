#pragma once
#include "UIScreen.h"

class UISuit: public BaseUIScreen
{
public:
	UISuit() {
	}
	UISuit(Transform setTransform, bool fill, LayerSetting layerSetting) {
		Init(setTransform, fill, layerSetting);
	}
	UISuit(Layer setLayer)
		: BaseUIScreen(setLayer) {
	}
	UISuit(Layer setLayer, int setDrawHandle)
		: BaseUIScreen(setLayer, setDrawHandle) {
	}
	UISuit(const UISuit& obj)
		: BaseUIScreen(obj) {
	}
	~UISuit() {
	}
	void Init(Transform setTransform, bool fill, LayerSetting layerSetting);
	void Proc() override;
	void Draw() override;
	void Teardown() override;

private:
	// ”wŒi
	UIScreenImage* _pBackground;
	// –h‹ï–¼
	UIScreenText* _pSuitName;
	// ƒ‰ƒ“ƒN
	UIScreenText* _pSuitRank;
	// –hŒä”{—¦
	UIScreenText* _pSuitDefense[(int)Type::MAX];
};

