#include "../header/OfficerStatePanic.h"
#include "../header/BaseOfficer.h"

void OfficerStatePanic::Update(BaseOfficer* officer)
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

void OfficerStatePanic::Enter(BaseOfficer* officer)
{
	officer->color = PANIC;
}

void OfficerStatePanic::Exit(BaseOfficer* officer)
{
	officer->color = IDLE;
}