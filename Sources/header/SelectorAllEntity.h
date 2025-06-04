#pragma once
#include "ITargetSelector.h"

class SelectorAllEntity: public ITargetSelector
{
public:
	std::vector<BaseCharacter*> SelectTargets(BaseCharacter* attacker) override;

};