#pragma once
#include "../header/BaseCharacterState.h"

class BaseCharacter;

/*
 * Sein
 * Officer�̊��N���X
 */
class CharacterController
{
public:
	CharacterController();
	~CharacterController(){};

	virtual void UpdateAI();
	virtual void DecideState();

protected:
	BaseCharacter* character;

private:


};