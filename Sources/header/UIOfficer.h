#pragma once
#include "UIOfficerParam.h"
#include "UIWeapon.h"
#include "UISuit.h"
#include "BaseOfficer.h"
#include "Const.h"

class UIOfficer : public BaseUIScreen
{
public:
	UIOfficer() {
	}
	UIOfficer(Transform setTransform, bool fill, LayerSetting layerSetting) {
		Init(setTransform, fill, layerSetting);
	}
	UIOfficer(Layer setLayer)
		: BaseUIScreen(setLayer) {
	}
	UIOfficer(Layer setLayer, int setDrawHandle)
		: BaseUIScreen(setLayer, setDrawHandle) {
	}
	UIOfficer(const UIOfficer& obj)
		: BaseUIScreen(obj) {
	}
	~UIOfficer() {
	}
	void Init(Transform setTransform, bool fill, LayerSetting layerSetting);
	void Proc() override;
	void Draw() override;
	void Teardown() override;

	void SetOfficer(BaseOfficer* officer);
private:
	// 背景
	UIScreenImage* _pBackground;
	// 名前
	UIScreenText* _pOfficerName;
	// 画像
	UIScreenImage* _pOfficerImage;
	// 武器
	UIWeapon* _pWeapon;
	// 防具
	UISuit* _pSuit;
	// パラメーター
	UIOfficerParam* _pOfficerParam[(int)Type::MAX];

	// 座標,サイズ(相対割合)
	
	// 背景
	const Vector2 BACKGROUND_SIZE = Vector2(1, 1);
	const Vector2 BACKGROUND_POS =  Vector2(0, 0);
	// 名前
	const Vector2 NAME_SIZE = Vector2(1, 0.1f);
	const Vector2 NAME_POS =  Vector2(0, -0.95f);
	// 画像
	const Vector2 IMAGE_SIZE = Vector2(0.35f, 0.6f);
	const Vector2 IMAGE_POS =  Vector2(-0.65f, -0.2f);
	// 武器
	const Vector2 WEAPON_SIZE = Vector2(0.65f, 0.3f);
	const Vector2 WEAPON_POS =  Vector2(0.35f, -0.45f);
	// 防具
	const Vector2 SUIT_SIZE = Vector2(0.65f, 0.3f);
	const Vector2 SUIT_POS =  Vector2(0.35f, 0.05f);
	// パラメーター
	const Vector2 PARAM_SIZE[(int)Type::MAX] = {
		Vector2(0.5f, 0.15f),
		Vector2(0.5f, 0.15f),
		Vector2(0.5f, 0.15f),
		Vector2(0.5f, 0.15f)
	};
	const Vector2 PARAM_POS[(int)Type::MAX] = {
		Vector2(-0.25f, 0.45f),
		Vector2(0.25f, 0.8f),
		Vector2(-0.25f, 0.45f),
		Vector2(0.25f, 0.8f)
	};
};

