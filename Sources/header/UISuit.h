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
	// îwåi
	UIScreenImage* _pBackground;
	// ñhãÔñº
	UIScreenText* _pSuitName;
	// ÉâÉìÉN
	UIScreenText* _pSuitRank;
	// ñhå‰î{ó¶
	UIScreenText* _pSuitDefense[(int)Type::MAX];

	// ç¿ïW,ÉTÉCÉY(ëäëŒäÑçá)

	// îwåi
	const Vector2 BACKGROUND_SIZE = Vector2(1, 1);
	const Vector2 BACKGROUND_POS =  Vector2(0, 0);
	// ñhãÔñº
	const Vector2 NAME_SIZE = Vector2(1, 0.3f);
	const Vector2 NAME_POS =  Vector2(0, -0.7f);
	// ÉâÉìÉN
	const Vector2 RANK_SIZE = Vector2(1, 0.2f);
	const Vector2 RANK_POS =  Vector2(0, -0.2f);
	// ñhå‰î{ó¶
	const Vector2 DEFENSE_SIZE[(int)Type::MAX] = {
		Vector2(0.5f, 0.15f),
		Vector2(0.5f, 0.15f),
		Vector2(0.5f, 0.15f),
		Vector2(0.5f, 0.15f)
	};
	const Vector2 DEFENSE_POS[(int)Type::MAX] = {
		Vector2(-0.25f, 0.3f),
		Vector2(0.25f, 0.3f),
		Vector2(-0.25f, 0.6f),
		Vector2(0.25f, 0.6f)
	};
};

