#pragma once
#include "../header/Const.h"
class UIScreenButton;
class UIEntity;
class UIOfficer;

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
	void SetActiveEntity(bool active);

private:
	std::vector<UIScreenButton*> _pOperationUIList;
	UIEntity* _pEntityUI;
	UIOfficer* _pOfficerUI;

	const float _OPERATION_SIZE_X = WINDOW_WIDTH / 6;
	const float _OPERATION_SIZE_Y = WINDOW_HEIGHT / 3;
};