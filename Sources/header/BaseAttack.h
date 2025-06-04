#pragma once
#include "../header/BaseCharacter.h"
#include "../header/ITargetSelector.h"

class BaseCharacter;

/*
 * Sein
 * UŒ‚ˆ—‚ÌŠî’ê
 */
class BaseAttack 
{
public:
	BaseAttack(ITargetSelector* selector){
	};
	~BaseAttack(){
	};

	virtual void Attack(BaseCharacter* attacker);

protected:
	ITargetSelector* targetSelector;
};