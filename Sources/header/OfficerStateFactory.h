#pragma once
#include "../header/BaseOfficerState.h"
#include "../header/OfficerStateIdle.h"
#include "../header/OfficerStateMove.h"
#include "../header/OfficerStateFight.h"
#include "../header/OfficerStatePanic.h"
#include "../header/OfficerStateDead.h"

class BaseOfficerState;

/*
 * Sein
 * Officerのステートを生成
 */
class OfficerStateFactory
{
public:
	static enum OfficerStateID
	{
		NONE = -1,
		OFFICER_IDLE,
		OFFICER_MOVE,
		OFFICER_FIGHT,
		OFFICER_PANIC,
		OFFICER_DEAD,
	};
	
	static BaseOfficerState* ChangeState(OfficerStateID stateID);
};