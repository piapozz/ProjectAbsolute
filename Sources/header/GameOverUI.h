#pragma once
#include "BasePopupUI.h"

class GameOverUI: public BasePopupUI
{
public:
	static std::string StaticTypeName() {
		return "ContinueResultUI";
	}

	GameOverUI();
	~GameOverUI(){
	};

private:
	const std::string _INFORMATION_TEXT = "ì‹Æ’B¬•s‰Â";
	const std::string _CONTINUE_TEXT = "Ä’§í";
};

