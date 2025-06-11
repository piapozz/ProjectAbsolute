#include "../header/CharacterStateIdle.h"
#include "../header/BaseCharacter.h"

void CharacterStateIdle::Update(BaseCharacter* character)
{

}

void CharacterStateIdle::Enter(BaseCharacter* character)
{
	character->color = IDLE;
	character->stateID = CharacterStateID::IDLE;

}

void CharacterStateIdle::Exit(BaseCharacter* character)
{
	character->color = IDLE;
}