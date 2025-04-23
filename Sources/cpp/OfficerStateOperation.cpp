#include "../header/OfficerStateOperation.h"
#include "../header/BaseOfficer.h"
#include "../header/SecureRoom.h"

OfficerStateOperation::OfficerStateOperation(SecureRoom* secureRoom)
{
	_secureRoom = secureRoom;
}

void OfficerStateOperation::Update(BaseOfficer* officer)
{

}

void OfficerStateOperation::Enter(BaseOfficer* officer)
{
	// Žû—eŠ‚É“ž’…‚µ‚½’Ê’m‚ðo‚·
	_secureRoom->StartOperation();
	officer->color = OPERATION;
	officer->canOrder = false;
}

void OfficerStateOperation::Exit(BaseOfficer* officer)
{
	officer->color = IDLE;
	officer->canOrder = true;
}