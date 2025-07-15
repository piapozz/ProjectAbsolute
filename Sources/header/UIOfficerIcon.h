#pragma once
#include "UIScreen.h"
#include "BaseOfficer.h"
class UIOfficerList;

// スタンバイの中で表示されるUIアイコン
class UIOfficerIcon: public BaseUIScreen
{
public:
	// コールバック
	static std::function<void(UIOfficerIcon*)> startDrackCallback;
	static std::function<void(UIOfficerIcon*)> onDrackCallback;
	static std::function<void(UIOfficerIcon*)> endDrackCallback;

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

	static std::string StaticTypeName() {
		return "UIOfficerIcon";
	}

	void SetOfficer(BaseOfficer* officer) {
		if (officer == nullptr) return;
		_officer = officer;
		_officerNameText->SetText(_officer->GetName());
		// _officerRankText->SetText(_officer->GetRankString());
		// _officerIconImage->SetImage(_officer->GetIconImage());
	}

	void SetOfficerList(UIOfficerList* officerList) {
		_officerList = officerList;
	}

	BaseOfficer* GetOfficer() const {
		return _officer;
	}

	UIOfficerList* GetOfficerList() const {
		return _officerList;
	}

	void StartDrack() {
		if (startDrackCallback != NULL) startDrackCallback(this);
	}
	void OnDrack() {
		if (onDrackCallback != NULL) onDrackCallback(this);
	}
	void EndDrack() {
		if (endDrackCallback != NULL) endDrackCallback(this);
	}

private:
	UIScreenImage* _backgroundImage;
	UIScreenText* _officerNameText;
	UIScreenText* _officerRankText;
	UIScreenImage* _officerIconImage;

	BaseOfficer* _officer = nullptr;
	// 所属リスト
	UIOfficerList* _officerList = nullptr;

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
	const Vector2 IMAGE_SIZE = Vector2(1, 1);
	const Vector2 IMAGE_POS =  Vector2(0, 0);
	/*const Vector2 IMAGE_SIZE = Vector2(1, 0.6f);
	const Vector2 IMAGE_POS =  Vector2(0, 0.4f);*/
};

