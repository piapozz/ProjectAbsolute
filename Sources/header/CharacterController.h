#pragma once
#include "../header/BaseCharacterState.h"

class BaseCharacter;

/*
 * Sein
 * ControllerのBase
 */
class CharacterController
{
public:
	CharacterController(){
	};
	CharacterController(BaseCharacter* character): character(character){
	};
	~CharacterController(){
	};

	virtual void UpdateAI() = 0;
	/// <summary>
	/// ステートを確認し、各ステートの遷移関数を実行
	/// </summary>
	virtual void DecideState() = 0;

	// ステートからステートの遷移を実行する関数
	virtual void UpdateIdleState(){};
	virtual void UpdateMoveState(){};
	virtual void UpdateFightState(){};

protected:
	BaseCharacter* character;

private:


};