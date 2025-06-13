#pragma once
#include "UIScreen.h"

class UISuit: public BaseUIScreen
{
public:
	UISuit();
	~UISuit();

private:
	// �w�i
	UIScreenImage* _pBackground;
	// �h�
	UIScreenText* _pSuitName;
	// �����N
	UIScreenText* _pSuitRank;
	// �h��{��
	UIScreenText* _pSuitDefense[(int)Type::MAX];
};

