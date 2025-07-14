#pragma once
#include "../header/BaseSuit.h"

class SuitTriangle : public BaseSuit
{
public:
	SuitTriangle()
	{
		suitName = "Triangle";
		suitID = 1;

		suitMultiplier[(int)Type::RED] = 1.0f;
		suitMultiplier[(int)Type::WHITE] = 2.0f;
		suitMultiplier[(int)Type::BLACK] = 2.0f;
		suitMultiplier[(int)Type::PALE] = 2.0f;
	}
};