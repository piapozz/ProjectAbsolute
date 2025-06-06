#pragma once
#include "../header/BaseCharacterState.h"
#include "../header/ITargetSelector.h"

/*
 * Sein
 * Officer��FightState
 */
class CharacterStateFight : public BaseCharacterState
{
public:
	void Update(BaseCharacter* character) override;
	void Enter(BaseCharacter* character) override;
	void Exit(BaseCharacter* character) override;

private:
	std::vector<BaseCharacter*> _targetCharacter;
	ITargetSelector* selector;
};