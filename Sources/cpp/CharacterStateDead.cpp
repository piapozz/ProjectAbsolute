#include "../header/CharacterStateDead.h"
#include "../header/BaseCharacter.h"

void CharacterStateDead::Update(BaseCharacter* character)
{
	character->SetHealth(0);
}

void CharacterStateDead::Enter(BaseCharacter* character)
{
	character->color = DEAD;
}

void CharacterStateDead::Exit(BaseCharacter* character)
{
	character->color = IDLE;
}