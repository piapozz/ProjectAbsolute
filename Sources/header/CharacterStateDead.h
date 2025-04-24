#pragma once
#include "../header/BaseCharacterState.h"

/*
 * Sein
 * Character��DeadState
 */
class CharacterStateDead : public BaseCharacterState
{
public:
	void Update(BaseCharacter* character) override;
	void Enter(BaseCharacter* character) override;
	void Exit(BaseCharacter* character) override;
};