#pragma once
#include "UIScreen.h"
#include "BaseOfficer.h"

class UIOfficerIcon;

class UIOfficerList: public BaseUIScreen
{
public:
	UIOfficerList() {
	}
	UIOfficerList(Transform setTransform, LayerSetting layerSetting) {
		Init(setTransform, layerSetting);
	}
	UIOfficerList(Layer setLayer)
		: BaseUIScreen(setLayer) {
	}
	UIOfficerList(Layer setLayer, int setDrawHandle)
		: BaseUIScreen(setLayer, setDrawHandle) {
	}
	UIOfficerList(const BaseUIScreen& obj)
		: BaseUIScreen(obj) {
	}
	~UIOfficerList() {
	}

	void Init(Transform setTrasnform, LayerSetting layerSetting);
	void Proc() override;
	void Draw() override;
	void Teardown() override;

	static std::string StaticTypeName() {
		return "UIOfficerList";
	}

	/// <summary>
	/// オフィサーリストの設定
	/// </summary>
	/// <param name="list"></param>
	void AddOfficer(BaseOfficer* officer);

	void RemoveOfficer(BaseOfficer* officer);

private:
	void DrawOfficerList();
	void SetIconPosition();
	std::vector<BaseOfficer*> officerList;
	std::vector<UIOfficerIcon*> officerIcons;
	UIScreenImage* backgroundImage;

	// 座標,サイズ
	const float WIN_X = WINDOW_WIDTH;
	const float WIN_Y = WINDOW_HEIGHT;

	// 職員アイコン
	const Vector2 OFFICER_ICON_SIZE = Vector2(WIN_X * (1.0f / 20.0f), WIN_Y * (2.0f / 20.0f));
};

