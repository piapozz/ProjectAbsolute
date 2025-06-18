#pragma once
#include "UIScreen.h"
#include "BaseWeapon.h"

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

	void SetWeapon(BaseWeapon& setWeapon);
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

	// À•W,ƒTƒCƒY(‘Š‘ÎŠ„‡)

	// ”wŒi
	const Vector2 BACKGROUND_SIZE = Vector2(1, 1);
	const Vector2 BACKGROUND_POS =  Vector2(0, 0);
	// •Ší–¼
	const Vector2 NAME_SIZE = Vector2(1, 0.3f);
	const Vector2 NAME_POS =  Vector2(0, -0.7f);
	// ƒ‰ƒ“ƒN
	const Vector2 RANK_SIZE = Vector2(1, 0.2f);
	const Vector2 RANK_POS =  Vector2(0, -0.2f);
	// UŒ‚‘®«
	const Vector2 TYPE_SIZE = Vector2(0.5f, 0.5f);
	const Vector2 TYPE_POS =  Vector2(-0.25f, 0.25f);
	// UŒ‚—Í
	const Vector2 ATTACK_SIZE = Vector2(0.5f, 0.5f);
	const Vector2 ATTACK_POS =  Vector2(0.25f, 0.25f);
};

