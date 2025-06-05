#pragma once
#include "ITargetSelector.h"

/*
 * Sein
 * ‹æ‰æ‚ğ‚Ü‚½‚¢‚Åˆê”Ô‹ß‚¢Officer‚ğ‘ÎÛ‚É‚Æ‚éƒNƒ‰ƒX
 */
class SelectorOutAreaNearOfficer: public ITargetSelector
{
public:
	std::vector<BaseCharacter*> SelectTargets(BaseCharacter* attacker) override;

private:

};