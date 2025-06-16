#pragma once
#include "UIScreen.h"

class UIWeapon : public BaseUIScreen
{
public:
	UIWeapon() {
	}
	UIWeapon(Transform setTransform, bool fill, LayerSetting layerSetting) {
		Init(setTransform, fill, layerSetting);
	}
	UIWeapon(Layer setLayer)
		: BaseUIScreen(setLayer) {
	}
	UIWeapon(Layer setLayer, int setDrawHandle)
		: BaseUIScreen(setLayer, setDrawHandle) {
	}
	UIWeapon(const UIWeapon& obj)
		: BaseUIScreen(obj) {
	}
	~UIWeapon() {
	}
	void Init(Transform setTransform, bool fill, LayerSetting layerSetting);
	void Proc() override;
	void Draw() override;
	void Teardown() override;
private:
	// ”wŒi
	UIScreenImage* _pBackground;
	// •Ší–¼
	UIScreenText* _pWeaponName;
	// ƒ‰ƒ“ƒN
	UIScreenText* _pWeaponRank;
	// UŒ‚‘®«
	UIScreenText* _pWeaponType;
	// UŒ‚—Í
	UIScreenText* _pWeaponAttack;
};

