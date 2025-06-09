#pragma once
#include "BaseUIScreen.h"
#include "UIScreenImage.h"

class Cursor : public BaseUIScreen
{
public:
	Cursor(){}
	Cursor(Vector2 setPosition, Vector2 setSize, bool fill, LayerSetting layerSetting)
		: BaseUIScreen(setPosition, setSize, layerSetting)
	{
		Init(setPosition, setSize, fill ,layerSetting);
	}
	~Cursor(){}
	void Init(Vector2 setPosition, Vector2 setSize,bool fill, LayerSetting layerSetting);
	void Proc() override;
	void Draw() override;

	static std::string StaticTypeName() {
		return "Cursor";
	}
private:
	UIScreenImage* _pImage;
};
