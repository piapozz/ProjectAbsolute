#pragma once
#include "ITargetSelector.h"

class SelectorNearEntityInRoom: public ITargetSelector
{
public:
	std::vector<BaseCharacter*> SelectTargets(BaseCharacter* attacker) override;

};