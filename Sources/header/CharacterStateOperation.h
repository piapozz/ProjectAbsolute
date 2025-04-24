#pragma once
#include "../header/BaseCharacterState.h"

class SecureRoom;

/*
 * Sein
 * Character‚ÌOperationState
 */
class CharacterStateOperation: public BaseCharacterState
{
public:
	CharacterStateOperation(SecureRoom* secureRoom);

	void Update(BaseCharacter* character) override;
	void Enter(BaseCharacter* character) override;
	void Exit(BaseCharacter* character) override;

private:
	SecureRoom* _secureRoom;

};