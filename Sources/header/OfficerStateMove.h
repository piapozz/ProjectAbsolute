#pragma once
#include "../header/BaseOfficerState.h"

/*
 * Sein
 * Officer‚ÌPanicMove
 */
class OfficerStateMove : public BaseOfficerState
{
public:
	void Update(BaseOfficer* officer) override;
	void Enter(BaseOfficer* officer) override;
	void Exit(BaseOfficer* officer) override;
};