#pragma once
#include "../header/BaseOfficer.h"

/*
 * Sein
 * �v���C���[������ł��Ȃ�Officer
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
