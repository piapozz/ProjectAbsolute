#pragma once
#include "../header/BaseOperation.h"

/*
 * Sakakura
 * �ڐG���
 */
class OperationContact: public BaseOperation
{
public:
	OperationContact(){}
	OperationContact(int masterEntityID, UIButton* setUI);
	~OperationContact(){}
};

