#pragma once
#include "ITargetSelector.h"

class SelectorAllOfficer: public ITargetSelector
{
public:
	std::vector<BaseCharacter*> SelectTargets(BaseCharacter* attacker) override;

};