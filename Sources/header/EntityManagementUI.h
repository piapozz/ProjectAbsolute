#pragma once
#include <vector>
#include "BaseUIScreen.h"

class EntityManagementTipsUI;
class UIScreenImage;
class UIScreenText;

class EntityManagementUI : public BaseUIScreen
{
public:
	EntityManagementUI(){}
	EntityManagementUI(Transform setTransform, LayerSetting layerSetting);
	~EntityManagementUI(){}

	void Draw() override;
	void SetActive(bool active);

	static std::string StaticTypeName() {
		return "EntityManagementUI";
	}

private:
	UIScreenImage* _BGImage;
	UIScreenText* _informationText;
	std::vector<EntityManagementTipsUI*> _tipsUIList;
	const Vector2 _INFORMATION_TEXT_POS = Vector2(0, -1.0f);
};

