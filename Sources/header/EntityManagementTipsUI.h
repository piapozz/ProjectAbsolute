#pragma once
#include "BaseObject.h"
#include "UIScreen.h"
class EntityManagementTipsUI : public BaseObject
{
public:
	EntityManagementTipsUI(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting, std::string tipsText);
	~EntityManagementTipsUI(){}

	void SetActive(bool active);
	inline void SetLock(bool isLock) { _isLock = isLock; }
	void Draw() override;

private:
	UIScreenText* _lockText;
	UIScreenText* _tipsInformation;
	UIScreenText* _tipsText;
	bool _isLock;
	const std::string _LOCK_TEXT = "ÉçÉbÉNíÜ";
	const std::string _TIPS_INFORMATION = "ä«óùï˚ñ@%d";
};

