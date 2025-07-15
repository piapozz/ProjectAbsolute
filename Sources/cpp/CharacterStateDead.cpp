#include "../header/CharacterStateDead.h"
#include "../header/BaseCharacter.h"

void CharacterStateDead::Update(BaseCharacter* character)
{
	character->SetHealth(0);

	if (_respawnTimer + _RESPAWN_COUNT <= GetNowCount())
	{
		std::function<void()> func = character->GetDeadEventCallBack();
		if (func != NULL) character->DeadEvent();
	}
}

void CharacterStateDead::Enter(BaseCharacter* character)
{
	character->color = DEAD;
	character->stateID = CharacterStateID::DEAD;
	_respawnTimer = GetNowCount();
	
	character->SetImpossible(false);
}

void CharacterStateDead::Exit(BaseCharacter* character)
{
	character->color = IDLE;
}