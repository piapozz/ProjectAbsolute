#include "../header/OfficerStateIdle.h"
#include "../header/BaseOfficer.h"

void OfficerStateIdle::Update(BaseOfficer* officer)
{

}

void OfficerStateIdle::Enter(BaseOfficer* officer)
{
	officer->color = IDLE;
}

void OfficerStateIdle::Exit(BaseOfficer* officer)
{
	officer->color = IDLE;
}