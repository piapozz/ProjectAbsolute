#pragma once
#include "ITargetSelector.h"

/*
 * Sein
 * 区画をまたいで一番近いOfficerを対象にとるクラス
 */
class SelectorOutAreaNearOfficer: public ITargetSelector
{
public:
	std::vector<BaseCharacter*> SelectTargets(BaseCharacter* attacker) override;

private:

};