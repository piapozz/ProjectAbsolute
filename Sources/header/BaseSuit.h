#pragma once
#include "../header/Const.h"

class BaseSuit
{
public:
	BaseSuit()
	{
		suitID = 0;

		suitMultiplier[(int)Type::RED] = 1.0f;
		suitMultiplier[(int)Type::WHITE] = 1.0f;
		suitMultiplier[(int)Type::BLACK] = 1.0f;
		suitMultiplier[(int)Type::PALE] = 2.0f;
	}

	virtual void Effect(){};
	virtual void Passive(){};

protected:
	// ID
	int suitID;
	// Še‘®«‚Ì‘Ï«
	float suitMultiplier[(int)Type::MAX];
	// ‰æ‘œ
	
	// à–¾•¶
};