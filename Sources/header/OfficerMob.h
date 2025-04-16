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

	void Init(Vector2 setPosition, int setOfficerID) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;

private:
};
