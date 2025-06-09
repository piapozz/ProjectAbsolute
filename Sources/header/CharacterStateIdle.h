#pragma once
#include "../header/BaseCharacterState.h"

/*
 * Sein
 * Officer‚ÌIdleState
 */
class CharacterStateIdle : public BaseCharacterState
{
public:
	void Update(BaseCharacter* character) override;
	void Enter(BaseCharacter* character) override;
	void Exit(BaseCharacter* character) override;

private:
	int _startCount = 0;
	const int _waitCount = 5000;
};