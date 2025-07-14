#include "../header/BaseController.h"
#include "../header/BaseCharacter.h"

void BaseController::UpdateAI()
{
	if(!isFreeze) DecideState();
}

void BaseController::DecideState()
{

}