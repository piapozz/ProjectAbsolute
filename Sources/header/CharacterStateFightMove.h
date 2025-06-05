#pragma once
#include "../header/BaseCharacterState.h"


/*
 * Sein
 * Character‚ÌFightMove
 */
class CharacterStateFightMove: public BaseCharacterState
{
public:
	CharacterStateFightMove(std::vector<Vector2> targetPosList, BaseCharacter* targetCharacter);

	void Update(BaseCharacter* character) override;
	void Enter(BaseCharacter* character) override;
	void Exit(BaseCharacter* character) override;

private:
	std::vector<Vector2> _routeList;
	BaseCharacter* _targetCharacter;

	int _arrayCount = 0;
	int speed = 2;
};