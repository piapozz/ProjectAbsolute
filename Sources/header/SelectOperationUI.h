#pragma once
#include "BaseUIScreen.h"
class UIScreenButton;

class SelectOperationUI : public BaseUIScreen
{
public:
	static std::string StaticTypeName() {
		return "SelectOperationUI";
	}

	SelectOperationUI();
	~SelectOperationUI(){};

	void Draw() override;
	
	void SetActive(bool active);
	std::vector<UIScreenButton*> GetOperationUIList() { return _pOperationUIList; }

private:
	std::vector<UIScreenButton*> _pOperationUIList;

	const Vector2 _UI_POSITION = Vector2(WINDOW_WIDTH / 12, WINDOW_HEIGHT - WINDOW_HEIGHT / 3);
	const Vector2 _UI_SCALE = Vector2(WINDOW_WIDTH / 6, WINDOW_HEIGHT / 3);
	const Transform _TRANSFORM = Transform(_UI_POSITION, _UI_SCALE);
	const LayerSetting _DEFAULT_LAYER = LayerSetting(false, false, Layer::MIDDLE);
	const float _OPERATION_SCALE = 0.5f;
};

