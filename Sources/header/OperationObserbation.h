#pragma once
#include "../header/BaseOperation.h"

/*
 * Sakakura
 * ŠÏ@ì‹Æ
 */
class OperationObserbation: public BaseOperation
{
public:
	OperationObserbation(){}
	OperationObserbation(int masterEntityID, UIButton* setUI):BaseOperation(masterEntityID, setUI){};
	~OperationObserbation(){}
};

