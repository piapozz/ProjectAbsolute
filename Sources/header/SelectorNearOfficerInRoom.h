#pragma once
#include "ITargetSelector.h"

class SelectorNearOfficerInRoom: public ITargetSelector
{
public:
	std::vector<BaseCharacter*> SelectTargets(BaseCharacter* attacker) override;

};