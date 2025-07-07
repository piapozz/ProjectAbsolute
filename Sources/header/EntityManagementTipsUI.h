#pragma once
#include "BaseUIScreen.h"

class UIScreenText;
class UIScreenImage;

class EntityManagementTipsUI : public BaseUIScreen
{
public:
	static std::string StaticTypeName() {
		return "EntityManagementTipsUI";
	}

	EntityManagementTipsUI(Transform setTransform, LayerSetting layerSetting, std::string tipsText, int tipsCount);
	~EntityManagementTipsUI(){}

	void Draw() override;
	inline void SetLock(bool isLock) { _isLock = isLock; }
	void SetTipsText(std::string setText);
	void SetFontSize(int setSize);

private:
	UIScreenImage* _BGImage;
	UIScreenText* _lockText;
	UIScreenText* _informationText;
	UIScreenText* _tipsText;
	bool _isLock;

	const Vector2 _LOCK_TEXT_POS = Vector2(-0.45f, 0);
	const std::string _LOCK_TEXT = "äYìñéñó·î≠ê∂Ç≈âèú";
	const Vector2 _INFORMATION_POS = Vector2(-0.2f, -0.95f);
	const std::string _INFORMATION_TEXT = "ä«óùï˚ñ@";
	const Vector2 _TIPS_TEXT_POS = Vector2(-0.95f, -0.3f);
	const int _TIPS_FONT_SIZE = 16;
};

