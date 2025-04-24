#include "../header/CharacterStateFight.h"
#include "../header/BaseCharacter.h"

void CharacterStateFight::Update(BaseCharacter* character)
{

}

void CharacterStateFight::Enter(BaseCharacter* character)
{
	character->color = FIGHT;
}

void CharacterStateFight::Exit(BaseCharacter* character)
{
	character->color = IDLE;
}