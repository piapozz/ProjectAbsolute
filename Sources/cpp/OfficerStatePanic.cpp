#include "../header/OfficerStatePanic.h"
#include "../header/BaseOfficer.h"

void OfficerStatePanic::Update(BaseOfficer* officer)
{

}

void OfficerStatePanic::Enter(BaseOfficer* officer)
{
	officer->color = PANIC;
}

void OfficerStatePanic::Exit(BaseOfficer* officer)
{
	officer->color = IDLE;
}