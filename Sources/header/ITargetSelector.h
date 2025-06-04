#pragma once
#include <vector>

class BaseCharacter;

/*
 * Sein
 * Selector�̃C���^�[�t�F�[�X
 */
class ITargetSelector 
{
public:
	virtual std::vector<BaseCharacter*> SelectTargets(BaseCharacter* attacker){
	};
	virtual ~ITargetSelector() {
	};
};