#pragma once
#include "UIScreen.h"

class UIOfficerParam : public BaseUIScreen
{
public:
	UIOfficerParam();
	~UIOfficerParam();
private:
	// �w�i
	UIScreenImage* _pBackground;
	// �p�����[�^�[��
	UIScreenText* _pParamName;
	// �p�����[�^�[�l
	UIScreenText* _pParamValue;
};

