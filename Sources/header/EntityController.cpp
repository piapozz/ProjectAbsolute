#include "../header/EntityController.h"
#include "../header/ObjectManager.h"
#include "../header/BaseCharacter.h"
#include "../header/SecureRoom.h"

void EntityController::UpdateAI()
{
	DecideState();
}

void EntityController::DecideState()
{
	BaseController::DecideState();

	character->ChangeState(CharacterStateID::PANIC);

	return;
}