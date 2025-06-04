#pragma once
#include "ITargetSelector.h"

class SelectorAllCharacter: public ITargetSelector
{
public:
	std::vector<BaseCharacter*> SelectTargets(BaseCharacter* attacker) override;

};