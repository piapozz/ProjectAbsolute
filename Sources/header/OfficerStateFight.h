#pragma once
#include "../header/BaseOfficerState.h"

/*
 * Sein
 * Officer‚ÌFightState
 */
class OfficerStateFight : public BaseOfficerState
{
public:
	void Update(Officer* officer) override;
	void Enter(Officer* officer) override;
	void Exit(Officer* officer) override;
};