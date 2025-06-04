#pragma once
#include <vector>

class BaseCharacter;

/*
 * Sein
 * Selectorのインターフェース
 */
class ITargetSelector 
{
public:
	virtual std::vector<BaseCharacter*> SelectTargets(BaseCharacter* attacker){
	};
	virtual ~ITargetSelector() {
	};
};