#include "../header/CharacterStateOperation.h"
#include "../header/BaseCharacter.h"
#include "../header/SecureRoom.h"

CharacterStateOperation::CharacterStateOperation(SecureRoom* secureRoom)
{
	_secureRoom = secureRoom;
}

void CharacterStateOperation::Update(BaseCharacter* character)
{

}

void CharacterStateOperation::Enter(BaseCharacter* character)
{
	// Žû—eŠ‚É“ž’…‚µ‚½’Ê’m‚ðo‚·
	_secureRoom->StartOperation();
	character->color = OPERATION;
	character->SetImpossible(false);
	character->stateID = CharacterStateID::OPERATION;
}

void CharacterStateOperation::Exit(BaseCharacter* character)
{
	character->color = IDLE;
	character->SetImpossible(true);
}