#pragma once
#include "ITargetSelector.h"

/*
 * Sein
 * �����܂����ň�ԋ߂�Officer��ΏۂɂƂ�N���X
 */
class SelectorOutAreaNearOfficer: public ITargetSelector
{
public:
	std::vector<BaseCharacter*> SelectTargets(BaseCharacter* attacker) override;

private:

};