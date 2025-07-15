#include "../header/CharacterStateDead.h"
#include "../header/BaseCharacter.h"

void CharacterStateDead::Update(BaseCharacter* character)
{
	character->SetHealth(0);
}

void CharacterStateDead::Enter(BaseCharacter* character)
{
	character->color = DEAD;
	character->stateID = CharacterStateID::DEAD;
	
	std::function<void()> func = character->GetDeadEventCallBack();
	if (func != NULL) character->DeadEvent();
	
	character->SetImpossible(false);
}

void CharacterStateDead::Exit(BaseCharacter* character)
{
	character->color = IDLE;
}