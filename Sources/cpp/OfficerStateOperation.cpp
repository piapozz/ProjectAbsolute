#include "../header/OfficerStateOperation.h"
#include "../header/BaseOfficer.h"

void OfficerStateOperation::Update(BaseOfficer* officer)
{

}

void OfficerStateOperation::Enter(BaseOfficer* officer)
{
	officer->color = OPERATION;
}

void OfficerStateOperation::Exit(BaseOfficer* officer)
{
	officer->color = IDLE;
}