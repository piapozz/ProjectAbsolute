#pragma once
#include "../header/BaseOfficer.h"

/*
 * Sein
 * プレイヤーが制御できないOfficer
 */
class OfficerMob : public BaseOfficer
{
public:
	OfficerMob();
	~OfficerMob();

	void Init(OfficerInitData data, int setOfficerID) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;

private:
};
