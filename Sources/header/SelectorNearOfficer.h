#pragma once
#include "ITargetSelector.h"

class SelectorNearOfficer: public ITargetSelector
{
public:
	std::vector<BaseCharacter*> SelectTargets(BaseCharacter* attacker) override;

};