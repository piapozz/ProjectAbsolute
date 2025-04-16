#pragma once
#include "../header/BaseOfficerState.h"
#include "../header/OfficerStateIdle.h"
#include "../header/OfficerStateMove.h"
#include "../header/OfficerStateFight.h"
#include "../header/OfficerStatePanic.h"
#include "../header/OfficerStateDead.h"
#include "../header/Const.h"

class BaseOfficerState;

/*
 * Sein
 * Officer�̃X�e�[�g�𐶐�
 */
class OfficerStateFactory
{
public:
	static BaseOfficerState* CreateState(OfficerStateID stateID);

};