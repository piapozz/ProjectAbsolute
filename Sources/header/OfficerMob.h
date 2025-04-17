#pragma once
#include "../header/BaseOfficer.h"

/*
 * Sein
 * �v���C���[������ł��Ȃ�Officer
 */
class OfficerMob : public BaseOfficer
{
public:
	int startTime;
	int now;

	OfficerMob();
	~OfficerMob();

	void Init(Vector2 setPosition, int setOfficerID) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;

private:
};
