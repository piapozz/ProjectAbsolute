#include "../header/CharacterController.h"
#include "../header/BaseCharacter.h"

void CharacterController::UpdateAI()
{
	DecideState();
}

void CharacterController::DecideState()
{
	//if (character->GetHealth() <= 0)
	//{
	//	character->ChangeState(CharacterStateID::DEAD);
	//	return;
	//}
}