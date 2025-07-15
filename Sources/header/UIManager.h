#pragma once
#include "../header/Const.h"
class UIScreenButton;
class UIEntity;
class UIOfficer;
class BaseOfficer;

class UIManager
{
public:
	static UIManager& Instance() {
		static UIManager instance;
		return instance;
	}

	UIManager();
	~UIManager();

	int GetFontHandle(int size);

private:
	int _fontHandle[FONT_SIZE_MAX];
};