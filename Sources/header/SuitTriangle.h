#pragma once
#include "../header/BaseSuit.h"

class SuitTriangle : public BaseSuit
{
public:
	SuitTriangle()
	{
		suitID = 1;

		multiplier[(int)Type::RED] = 0.5f;
		multiplier[(int)Type::WHITE] = 2.0f;
		multiplier[(int)Type::BLACK] = 2.0f;
		multiplier[(int)Type::PALE] = 2.0f;
	}
};