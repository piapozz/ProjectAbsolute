#pragma once
#include "../header/BaseCharacterState.h"

/*
 * Sein
 * Character‚ĚDeadState
 */
class CharacterStateDead : public BaseCharacterState
{
public:
	void Update(BaseCharacter* character) override;
	void Enter(BaseCharacter* character) override;
	void Exit(BaseCharacter* character) override;
};