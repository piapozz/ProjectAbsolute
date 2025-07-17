#pragma once
#include <functional>
#include "BaseUIScreen.h"
class UIScreenImage;
class UIScreenText;
class UIScreenButton;

class BasePopupUI : public BaseUIScreen
{
public:
	BasePopupUI();
	~BasePopupUI(){};

	void Init();
	void Draw() override;
	void SetCallback(std::function<void()> setCallback);
	void SetActive(bool setActive) override;

protected:
	UIScreenImage* BGImage;
	UIScreenText* informationText;
	UIScreenButton* button;

	const Vector2 POS = Vector2(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	const Vector2 SCALE = Vector2(WINDOW_WIDTH / 4, WINDOW_HEIGHT / 2);
	const Transform TRANSFORM = Transform(POS, SCALE);
	const LayerSetting DEFAULT_LAYER = LayerSetting(false, false, Layer::MIDDLE);
	const Vector2 INFORMATION_POS = Vector2(0.0f, -0.5f);
	const Vector2 CONTINUE_POS = Vector2(0.0f, 0.5f);
	const Vector2 CONTINUE_SCALE = Vector2(0.5f, 0.2f);
};

