#pragma once
#include "BaseUIScreen.h"
#include "UIScreen.h"

class EntityEscapeUI : public BaseUIScreen
{
public:
	EntityEscapeUI(){}
	EntityEscapeUI(Transform setTransform, LayerSetting layerSetting);
	~EntityEscapeUI(){}

	void SetActive(bool active);
	inline void SetLock(bool isLock){ _isLock = isLock; }
	void Draw();

	static std::string StaticTypeName() {
		return "EntityEscapeUI";
	}

private:
	UIScreenImage* _BGImage;
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

