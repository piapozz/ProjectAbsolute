#pragma once
#include "ITargetSelector.h"

class SelectorFarEntityInRoom: public ITargetSelector
{
public:
	std::vector<BaseCharacter*> SelectTargets(BaseCharacter* attacker) override;

};