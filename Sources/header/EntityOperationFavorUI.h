#pragma once
#include "BaseUIScreen.h"
#include "UIScreen.h"

class EntityOperationFavorUI : public BaseUIScreen
{
public:
	static std::string StaticTypeName() {
		return "EntityOperationFavorUI";
	}

	EntityOperationFavorUI(){}
	EntityOperationFavorUI(Transform setTransform, LayerSetting layerSetting);
	~EntityOperationFavorUI(){}

	void Draw() override;

private:
	UIScreenImage* _BGImage;
	UIScreenText* _lockText;
	UIScreenText* _information;
};

