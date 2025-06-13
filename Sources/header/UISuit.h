#pragma once
#include "UIScreen.h"

class UISuit: public BaseUIScreen
{
public:
	UISuit();
	~UISuit();

private:
	// ”wŒi
	UIScreenImage* _pBackground;
	// –h‹ï–¼
	UIScreenText* _pSuitName;
	// ƒ‰ƒ“ƒN
	UIScreenText* _pSuitRank;
	// –hŒä”{—¦
	UIScreenText* _pSuitDefense[(int)Type::MAX];
};

