#pragma once
#include "../header/BaseCharacter.h"

class BaseCharacter;

/*
 * Sein
 * UŒ‚ˆ—‚ÌŠî’ê
 */
class BaseAttack 
{
public:
	BaseAttack(){
	};
	~BaseAttack(){
	};

	virtual void Attack(BaseCharacter* attacker, BaseCharacter* characters);
};