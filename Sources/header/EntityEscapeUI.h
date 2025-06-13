#pragma once
#include "BaseObject.h"
#include "UIScreen.h"

class EntityEscapeUI : public BaseObject
{
public:
	EntityEscapeUI(Transform setTransform, LayerSetting layerSetting, std::string tipsText);
	~EntityEscapeUI(){}

	void SetActive(bool active);
	inline void SetLock(bool isLock){ _isLock = isLock; }
	void Draw();

private:
	UIScreenText* _lockText;
	UIScreenText* _escapeInformation;
	UIScreenText* _runawayCountInformation;
	UIScreenText* _runawayCount;
	UIScreenText* _defenceInformation;
	UIScreenText* _redDefence;
	UIScreenText* _whiteDefence;
	UIScreenText* _blackDefence;
	UIScreenText* _blueDefence;

	bool _isLock;
	const std::string _LOCK_TEXT = "ÉçÉbÉNíÜ";
	const std::string _TIPS_INFORMATION = "ä«óùï˚ñ@%d";
};

