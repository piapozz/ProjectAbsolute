#pragma once
#include "../header/BaseOfficer.h"

/*
 * Sein
 * �v���C���[������ł���Officer
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
