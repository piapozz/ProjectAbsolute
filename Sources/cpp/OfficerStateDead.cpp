#include "../header/OfficerStateDead.h"
#include "../header/BaseOfficer.h"

void OfficerStateDead::Update(BaseOfficer* officer)
{
	officer->SetHealth(0);
}

void OfficerStateDead::Enter(BaseOfficer* officer)
{
	officer->color = DEAD;
}

void OfficerStateDead::Exit(BaseOfficer* officer)
{
	officer->color = IDLE;
}