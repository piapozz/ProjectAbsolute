#pragma once
#include "BaseUIScreen.h"
#include "UIScreenImage.h"

class Cursor : public BaseUIScreen
{
public:
	Cursor(){}
	Cursor(Transform setTransform, bool fill, LayerSetting layerSetting)
		: BaseUIScreen(setTransform, layerSetting)
	{
		Init(setTransform, fill ,layerSetting);
	}
	~Cursor(){}
	void Init(Transform setTransform, bool fill, LayerSetting layerSetting);
	void Proc() override;
	void Draw() override;

	static std::string StaticTypeName() {
		return "Cursor";
	}
private:
	UIScreenImage* _pImage;
};
