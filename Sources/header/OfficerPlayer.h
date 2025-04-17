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

	void Init(Vector2 setPosition, int setOfficerID) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;

	void MoveToTargetPos(std::vector<std::vector<int>> stageData, Vector2 start, Vector2 goal);

private:
};
