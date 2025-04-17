#pragma once
#include "../header/BaseOfficerState.h"

/*
 * Sein
 * Officer‚ÌPanicMove
 */
class OfficerStateMove : public BaseOfficerState
{
public:
	OfficerStateMove(std::vector<Vector2> targePostList);

	void Update(BaseOfficer* officer) override;
	void Enter(BaseOfficer* officer) override;
	void Exit(BaseOfficer* officer) override;
private:
	std::vector<Vector2> _routeList;
	int _arrayCount;
};