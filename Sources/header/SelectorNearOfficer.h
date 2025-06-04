#pragma once
#include "ITargetSelector.h"

class NearestEnemySelector: public ITargetSelector 
{
public:
	std::vector<BaseCharacter*> SelectTargets(BaseCharacter* attacker) override;

};