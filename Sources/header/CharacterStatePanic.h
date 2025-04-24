#pragma once
#include "../header/BaseCharacterState.h"

/*
 * Sein
 * Officer��PanicState
 */
class CharacterStatePanic : public BaseCharacterState
{
public:
	void Update(BaseCharacter* character) override;
	void Enter(BaseCharacter* character) override;
	void Exit(BaseCharacter* character) override;
};