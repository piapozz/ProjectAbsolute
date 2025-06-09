#pragma once
#include <vector>
#include "BaseObject.h"

class EntityManagementTipsUI;

class EntityManagementUI : public BaseObject
{
public:
	EntityManagementUI(){}
	~EntityManagementUI(){}

	void Draw() override;
	void SetActive(bool active);

private:
	std::vector<EntityManagementTipsUI*> _tipsUIList;
};

