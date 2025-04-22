#pragma once
#include <vector>
#include "../header/BaseOfficerState.h"
#include "../header/OfficerStateIdle.h"
#include "../header/OfficerStateMove.h"
#include "../header/OfficerStateOperation.h"
#include "../header/OfficerStateOperationMove.h"
#include "../header/OfficerStateFight.h"
#include "../header/OfficerStatePanic.h"
#include "../header/OfficerStateDead.h"
#include "../header/StateArgs.h"
#include "../header/Const.h"

class BaseOfficerState;

/*
 * Sein
 * Officerのステートを生成
 */
class OfficerStateFactory
{
public:
	std::vector<Vector2> targetPosList;
	SecureRoom* secureRoom;

	static BaseOfficerState* CreateState(OfficerStateID stateID, StateArgs* args = nullptr);

};