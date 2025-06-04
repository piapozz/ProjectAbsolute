#pragma once
#include "../header/Const.h"
class UIScreenButton;

class UIManager
{
public:
	UIManager();
	~UIManager(){}

	static std::vector<UIScreenButton*> GetOperationUIList();
	static void SetActiveOperationUI(bool active);

private:
	static std::vector<UIScreenButton*> _pOperationUIList;
	const float _SCREEN_UI_SIZE_X = WINDOW_WIDTH / 6;
	const float _SCREEN_UI_SIZE_Y = WINDOW_HEIGHT / 3;
};