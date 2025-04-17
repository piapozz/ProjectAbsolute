#include "../header/OfficerStateFight.h"
#include "../header/BaseOfficer.h"

void OfficerStateFight::Update(BaseOfficer* officer)
{

}

void OfficerStateFight::Enter(BaseOfficer* officer)
{
	officer->color = FIGHT;
}

void OfficerStateFight::Exit(BaseOfficer* officer)
{
	officer->color = IDLE;
}