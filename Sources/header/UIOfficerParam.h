#pragma once
#include "UIScreen.h"

class UIOfficerParam : public BaseUIScreen
{
public:
	UIOfficerParam();
	~UIOfficerParam();
private:
	// 背景
	UIScreenImage* _pBackground;
	// パラメーター名
	UIScreenText* _pParamName;
	// パラメーター値
	UIScreenText* _pParamValue;
};

