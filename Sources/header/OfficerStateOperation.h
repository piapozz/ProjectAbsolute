#pragma once
#include "../header/BaseOfficerState.h"

/*
 * Sein
 * Officer��OperationState
 */
class OfficerStateOperation: public BaseOfficerState
{
public:
	void Update(BaseOfficer* officer) override;
	void Enter(BaseOfficer* officer) override;
	void Exit(BaseOfficer* officer) override;
};