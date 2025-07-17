#pragma once
#include "BasePopupUI.h"

class ContinueResultUI : public BasePopupUI
{
public:
	static std::string StaticTypeName() {
		return "ContinueResultUI";
	}

	ContinueResultUI();
	~ContinueResultUI(){};

private:
	const std::string _INFORMATION_TEXT = "–{“ú‚Ìì‹Æ–Ú•W’B¬";
	const std::string _CONTINUE_TEXT = "ì‹Æ•ñ‚Ö";
};
