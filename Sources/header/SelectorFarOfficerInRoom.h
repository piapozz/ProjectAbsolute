#pragma once
#include "ITargetSelector.h"

class SelectorFarOfficerInRoom: public ITargetSelector
{
public:
	std::vector<BaseCharacter*> SelectTargets(BaseCharacter* attacker) override;

};