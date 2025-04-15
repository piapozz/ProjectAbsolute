#pragma once
#include "../header/BaseOfficerState.h"

/*
 * Sein
 * Officer��DeadState
 */
class OfficerStateDead : public BaseOfficerState
{
public:
	void Update(Officer* officer) override;
	void Enter(Officer* officer) override;
	void Exit(Officer* officer) override;
};