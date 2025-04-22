#pragma once
#include "../header/BaseOfficerState.h"

class SecureRoom;

/*
 * Sein
 * Officer‚ÌOperationMoveState
 */
class OfficerStateOperationMove: public BaseOfficerState
{
public:
	OfficerStateOperationMove(std::vector<Vector2> targetPosList, SecureRoom* secureRoom);

	void Update(BaseOfficer* officer) override;
	void Enter(BaseOfficer* officer) override;
	void Exit(BaseOfficer* officer) override;

	void TowardsNotice();
	void ArriveNotice();

private:
	std::vector<Vector2> _routeList;
	SecureRoom* _secureRoom;
	int _arrayCount;
	int speed = 2;

};