#pragma once
#include "../header/BaseOfficer.h"

/*
 * Sein
 * ƒvƒŒƒCƒ„[‚ª§Œä‚Å‚«‚È‚¢Officer
 */
class OfficerMob : public BaseOfficer
{
public:
	OfficerMob();
	~OfficerMob();

	void Init() override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;

private:
};
