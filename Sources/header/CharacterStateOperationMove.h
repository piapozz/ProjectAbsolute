#pragma once
#include "../header/BaseCharacterState.h"

class SecureRoom;

/*
 * Sein
 * Character‚ÌOperationMoveState
 */
class CharacterStateOperationMove: public BaseCharacterState
{
public:
	CharacterStateOperationMove(std::vector<Vector2> targetPosList, SecureRoom* secureRoom);

	void Update(BaseCharacter* character) override;
	void Enter(BaseCharacter* character) override;
	void Exit(BaseCharacter* character) override;

private:
	std::vector<Vector2> _routeList;
	SecureRoom* _secureRoom;
	int _arrayCount = 0;
	int speed = 2;

};