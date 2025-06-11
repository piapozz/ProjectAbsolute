#pragma once
#include <DxLib.h>
#include <vector>
#include "../header/CommonModule.h"
#include "../header/Const.h"

// �O���錾
class BaseCharacter;

/*
 * Sein
 * Officer��State�̊��N���X
 */
class BaseCharacterState
{
public:
	virtual void Update(BaseCharacter* character){};
	virtual void Enter(BaseCharacter* character){};
	virtual void Exit(BaseCharacter* character){};

	inline bool EndState(){ return endState; }

	unsigned int NONE = GetColor(0, 255, 255);		
	unsigned int IDLE = GetColor(255, 255, 255);	// ��
	unsigned int MOVE = GetColor(0, 255, 0);		// ��
	unsigned int FIGHT = GetColor(255, 150, 0);		// �I�����W
	unsigned int OPERATION = GetColor(0, 0, 255);		// ��
	unsigned int OPERATION_MOVE = GetColor(100, 100, 255);		// ��
	unsigned int PANIC = GetColor(255, 0, 255);		// ��
	unsigned int DEAD = GetColor(255, 0, 0);		// ��

private:
	bool endState = false;
};