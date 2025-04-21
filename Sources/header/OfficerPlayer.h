#pragma once
#include "../header/BaseOfficer.h"

/*
 * Sein
 * ƒvƒŒƒCƒ„[‚ª‘€ì‚Å‚«‚éOfficer
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
};
