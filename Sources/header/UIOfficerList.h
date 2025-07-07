#pragma once
#include "UIScreen.h"
#include "BaseOfficer.h"

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

	/// <summary>
	/// オフィサーリストの設定
	/// </summary>
	/// <param name="list"></param>
	void SetOfficerList(std::vector<BaseOfficer*> list) { officerList = list; }

private:
	void DrawOfficerList();
	std::vector<BaseOfficer*> officerList;
	UIScreenImage* backgroundImage;
};

