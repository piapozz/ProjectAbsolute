#pragma once
#include <vector>
#include "BaseObject.h"
#include "UIScreen.h"

class EntityManagementTipsUI;

class EntityManagementUI : public BaseObject
{
public:
	EntityManagementUI(Transform setTransform, LayerSetting layerSetting);
	~EntityManagementUI(){}

	void Draw() override;
	void SetActive(bool active);

private:
	UIScreenText* _informationText;
	std::vector<EntityManagementTipsUI*> _tipsUIList;
};

