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
	static std::string StaticTypeName() {
		return "OfficerMob";
	}

	void Init(OfficerInitData data, int setOfficerID) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;

private:
};
