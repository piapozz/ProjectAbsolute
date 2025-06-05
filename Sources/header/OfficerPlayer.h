#pragma once
#include "../header/BaseOfficer.h"
#include "../header/UISlider.h"

/*
 * Sein
 * プレイヤーが操作できるOfficer
 */
class OfficerPlayer : public BaseOfficer
{
public:
	OfficerPlayer(){
	};
	OfficerPlayer(OfficerInitData data, int setOfficerID, LayerSetting layerSetting)
	{
		Init(data, setOfficerID, layerSetting);
	};
	~OfficerPlayer(){
	};

	static std::string StaticTypeName() {
		return "OfficerPlayer";
	}

	void Init(OfficerInitData data, int setOfficerID, LayerSetting layerSetting) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	void ClickEvent() override;

private:
	// スライダー
	UISlider* slider;
};
