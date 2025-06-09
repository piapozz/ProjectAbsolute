#pragma once
#include "BaseUIScreen.h"

class Cursor : public BaseUIScreen
{
public:
	Cursor(){}
	Cursor(Vector2 setPosition, Vector2 setSize, bool fill, LayerSetting layerSetting)
		: BaseUIScreen(setPosition, setSize, fill, layerSetting) {}
	~Cursor(){}
	void Proc() override;
	void Draw() override;

	static std::string StaticTypeName() {
		return "Cursor";
	}
};
