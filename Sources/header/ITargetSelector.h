#pragma once
#include <vector>
#include "../header/Const.h"

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