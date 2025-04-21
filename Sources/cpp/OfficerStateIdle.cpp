#include "../header/OfficerStateIdle.h"
#include "../header/BaseOfficer.h"

void OfficerStateIdle::Update(BaseOfficer* officer)
{
	std::vector<Vector2> routeList;
	routeList.push_back({0, 0});
	routeList.push_back({100, 100});
	routeList.push_back({-100, -100});
	routeList.push_back({-100, 100});
	StateArgs* args = new StateArgs();
	args->targetPosList = routeList;
	officer->ChangeState(OfficerStateID::OFFICER_MOVE, args);

}

void OfficerStateIdle::Enter(BaseOfficer* officer)
{
	officer->color = IDLE;
}

void OfficerStateIdle::Exit(BaseOfficer* officer)
{
	officer->color = IDLE;
}