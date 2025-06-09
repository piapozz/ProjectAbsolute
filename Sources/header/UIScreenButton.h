#pragma once
#include "UIScreenImage.h"
#include "UIScreenText.h"
#include <functional>
/*
* Ishihara
* UIスクリーンボタン
*/
class UIScreenButton : public BaseUIScreen
{
public:
	UIScreenButton() {}
	UIScreenButton(Vector2 setPosition, Vector2 setSize, bool fill, LayerSetting layerSetting) {
		Init(setPosition, setSize, fill, layerSetting);
	}
	UIScreenButton(Layer setLayer)
		: BaseUIScreen(setLayer) {}
	UIScreenButton(Layer setLayer, int setDrawHandle)
		: BaseUIScreen(setLayer, setDrawHandle) {}
	UIScreenButton(const UIScreenButton& obj)
		: BaseUIScreen(obj) {}
	~UIScreenButton() {}
	void Init(Vector2 setPosition, Vector2 setSize, bool fill, LayerSetting layerSetting);
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	void ClickEvent() override { _callback(); }

	static std::string StaticTypeName() {
		return "UIScreenButton";
	}

	void SetText(std::string str) {
		_pText->SetText(str);
	}

	void SetTextColor(int r = 255, int g = 255, int b = 255) {
		_pText->SetTextColor(r, g, b);
	}

	void SetActive(bool active) override {
		BaseObject::SetActive(active);
		_pImage->SetActive(active);
		_pText->SetActive(active);
	}

	/// <summary>
	/// コールバックの設定
	/// </summary>
	/// <param name="callback"></param>
	void SetCallback(std::function<void()> callback) { _callback = callback; }
private:
	UIScreenText* _pText;
	UIScreenImage* _pImage;
	// コールバック
	std::function<void()> _callback;
};
