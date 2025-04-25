#pragma once
#include <vector>
#include "../header/BaseCharacterState.h"
#include "../header/CharacterStateIdle.h"
#include "../header/CharacterStateMove.h"
#include "../header/CharacterStateOperation.h"
#include "../header/CharacterStateOperationMove.h"
#include "../header/CharacterStateFight.h"
#include "../header/CharacterStatePanic.h"
#include "../header/CharacterStateDead.h"
#include "../header/StateArgs.h"
#include "../header/Const.h"

class BaseCharacterState;

/*
 * Sein
 * Officerのステートを生成
 */
class CharacterStateFactory
{
public:
	std::vector<Vector2> targetPosList;
	SecureRoom* secureRoom;

	static BaseCharacterState* CreateState(CharacterStateID stateID, StateArgs* args = nullptr);

};