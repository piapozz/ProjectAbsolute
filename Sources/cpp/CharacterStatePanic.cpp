#include "../header/CharacterStatePanic.h"
#include "../header/BaseCharacter.h"

void CharacterStatePanic::Update(BaseCharacter* character)
{

}

void CharacterStatePanic::Enter(BaseCharacter* character)
{
	character->color = PANIC;
	character->stateID = CharacterStateID::PANIC;
}

void CharacterStatePanic::Exit(BaseCharacter* character)
{
	character->color = IDLE;
}