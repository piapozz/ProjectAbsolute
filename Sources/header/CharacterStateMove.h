#pragma once
#include "../header/BaseCharacterState.h"

/*
 * Sein
 * Character‚ÌPanicMove
 */
class CharacterStateMove : public BaseCharacterState
{
public:
	CharacterStateMove(std::vector<Vector2> targetPosList);

	void Update(BaseCharacter* character) override;
	void Enter(BaseCharacter* character) override;
	void Exit(BaseCharacter* character) override;

private:
	std::vector<Vector2> _routeList;
	int speed = 2;
};