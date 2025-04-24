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
	OfficerPlayer();
	~OfficerPlayer();

	void Init(OfficerInitData data, int setOfficerID) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	void ClickEvent() override;

private:
	// スライダー
	UISlider* slider;
};
