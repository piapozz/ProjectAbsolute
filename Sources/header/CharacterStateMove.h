#pragma once
#include "../header/BaseCharacterState.h"

/*
 * Sein
 * Character‚ÌPanicMove
 */
class CharacterStateMove : public BaseCharacterState
{
public:
	CharacterStateMove(std::vector<Vector2> targetPosList, CharacterStateID nextStateID);

	void Update(BaseCharacter* character) override;
	void Enter(BaseCharacter* character) override;
	void Exit(BaseCharacter* character) override;

private:
	std::vector<Vector2> _routeList;
	CharacterStateID _nextStateID;
	int _arrayCount = 0;
	int speed = 2;

};