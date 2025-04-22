#pragma once
#include "../header/BaseOfficer.h"
#include "../header/UISlider.h"

/*
 * Sein
 * �v���C���[������ł���Officer
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

	void MoveToTargetPos(std::vector<Vector2> routeList);

private:
	// �X���C�_�[
	UISlider* slider;
};
