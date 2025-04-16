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

	void Init() override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;

private:
};
