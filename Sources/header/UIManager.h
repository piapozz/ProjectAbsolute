#pragma once
#include "../header/Const.h"
class UIScreenButton;

class UIManager
{
public:
	static UIManager& Instance() {
		static UIManager instance;
		return instance;
	}

	UIManager();
	~UIManager(){}

	std::vector<UIScreenButton*> GetOperationUIList();
	void SetActiveOperationUI(bool active);

private:
	std::vector<UIScreenButton*> _pOperationUIList;
	const float _SCREEN_UI_SIZE_X = WINDOW_WIDTH / 6;
	const float _SCREEN_UI_SIZE_Y = WINDOW_HEIGHT / 3;
};