#pragma once
#include <functional>
#include "BaseUIScreen.h"
class UIScreenImage;
class UIScreenText;
class UIScreenButton;

class ContinueResultUI : public BaseUIScreen
{
public:
	static std::string StaticTypeName() {
		return "ContinueResultUI";
	}

	ContinueResultUI();
	~ContinueResultUI(){};

	void Init();
	void Draw() override;
	void SetCallback(std::function<void()> setCallback);

private:
	UIScreenImage* _BGImage;
	UIScreenText* _informationText;
	UIScreenButton* _continueButton;

	const Vector2 _POS = Vector2(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	const Vector2 _SCALE = Vector2(WINDOW_WIDTH / 4, WINDOW_HEIGHT / 2);
	const Transform _TRANSFORM = Transform(_POS, _SCALE);
	const LayerSetting _DEFAULT_LAYER = LayerSetting(false, false, Layer::MIDDLE);
	const Vector2 _INFORMATION_POS = Vector2(-0.5f, -0.5f);
	const std::string _INFORMATION_TEXT = "ñ{ì˙ÇÃçÏã∆ñ⁄ïWíBê¨";
	const Vector2 _CONTINUE_POS = Vector2(0.0f, 0.5f);
	const Vector2 _CONTINUE_SCALE = Vector2(0.5f, 0.2f);
	const std::string _CONTINUE_TEXT = "çÏã∆ïÒçêÇ÷";
};
