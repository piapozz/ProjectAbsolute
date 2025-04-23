#pragma once
#include "../header/BaseOfficerState.h"

class SecureRoom;

/*
 * Sein
 * Officer‚ÌOperationState
 */
class OfficerStateOperation: public BaseOfficerState
{
public:
	OfficerStateOperation(SecureRoom* secureRoom);

	void Update(BaseOfficer* officer) override;
	void Enter(BaseOfficer* officer) override;
	void Exit(BaseOfficer* officer) override;

private:
	SecureRoom* _secureRoom;

};