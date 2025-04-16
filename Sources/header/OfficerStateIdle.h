#pragma once
#include "../header/BaseOfficerState.h"

/*
 * Sein
 * Officer��IdleState
 */
class OfficerStateIdle : public BaseOfficerState
{
public:
	void Update(BaseOfficer* officer) override;
	void Enter(BaseOfficer* officer) override;
	void Exit(BaseOfficer* officer) override;
};