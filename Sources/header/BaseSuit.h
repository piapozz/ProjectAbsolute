#pragma once
#include "../header/Const.h"

class BaseSuit
{
public:
	BaseSuit()
	{
		suitName = "";
		suitID = 0;

		suitMultiplier[(int)Type::RED] = 1.0f;
		suitMultiplier[(int)Type::WHITE] = 1.0f;
		suitMultiplier[(int)Type::BLACK] = 1.0f;
		suitMultiplier[(int)Type::PALE] = 2.0f;
	}

	virtual void Effect(){};
	virtual void Passive(){};

	inline std::string GetName(){ return suitName; }
	inline float* GetMultipliers(){ return suitMultiplier; }

protected:
	std::string suitName;
	// ID
	int suitID;
	// Še‘®«‚Ì‘Ï«
	float suitMultiplier[(int)Type::MAX];
	// ‰æ‘œ
	
	// à–¾•¶
};