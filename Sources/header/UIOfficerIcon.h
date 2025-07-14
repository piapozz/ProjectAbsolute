#pragma once
#include "UIScreen.h"
#include "BaseOfficer.h"

// スタンバイの中で表示されるUIアイコン
class UIOfficerIcon: public BaseUIScreen
{
public:
	UIOfficerIcon() {
	}
	UIOfficerIcon(Transform setTransform, LayerSetting layerSetting) {
		Init(setTransform, layerSetting);
	}
	UIOfficerIcon(Layer setLayer)
		: BaseUIScreen(setLayer) {
	}
	UIOfficerIcon(Layer setLayer, int setDrawHandle)
		: BaseUIScreen(setLayer, setDrawHandle) {
	}
	UIOfficerIcon(const BaseUIScreen& obj)
		: BaseUIScreen(obj) {
	}
	~UIOfficerIcon() {
	}

	void Init(Transform setTrasnform, LayerSetting layerSetting);
	void Proc() override;
	void Draw() override;
	void Teardown() override;

	void SetOfficer(BaseOfficer* officer) {
		if (officer == nullptr) return;
		_officerNameText->SetText(officer->GetName());
		// _officerRankText->SetText(officer->GetRankString());
		// _officerIconImage->SetImage(officer->GetIconImage());
	}

private:
	UIScreenImage* _backgroundImage;
	UIScreenText* _officerNameText;
	UIScreenText* _officerRankText;
	UIScreenImage* _officerIconImage;

	// 座標,サイズ(相対割合)

	// 背景
	const Vector2 BACKGROUND_SIZE = Vector2(1, 1);
	const Vector2 BACKGROUND_POS =  Vector2(0, 0);
	// ランク
	const Vector2 RANK_SIZE = Vector2(1, 0.2f);
	const Vector2 RANK_POS =  Vector2(0, -0.8f);
	// 名前
	const Vector2 NAME_SIZE = Vector2(1, 0.2f);
	const Vector2 NAME_POS =  Vector2(0, -0.6f);
	// 画像
	const Vector2 IMAGE_SIZE = Vector2(1, 0.6f);
	const Vector2 IMAGE_POS =  Vector2(0, 0.3f);
};

