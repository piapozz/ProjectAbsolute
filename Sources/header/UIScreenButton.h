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
	UIScreenButton(Transform setTransform, bool fill, LayerSetting layerSetting) {
		Init(setTransform, fill, layerSetting);
	}
	UIScreenButton(Layer setLayer)
		: BaseUIScreen(setLayer) {}
	UIScreenButton(Layer setLayer, int setDrawHandle)
		: BaseUIScreen(setLayer, setDrawHandle) {}
	UIScreenButton(const UIScreenButton& obj)
		: BaseUIScreen(obj) {}
	~UIScreenButton() {}
	void Init(Transform setTransform, bool fill, LayerSetting layerSetting);
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

	void SetTextColor(int color) {
		_pText->SetTextColor(color);
	}

	void SetActive(bool active) override {
		BaseObject::SetActive(active);
		_pImage->SetActive(active);
		_pText->SetActive(active);
	}

	void OnCursor() override {
		_pImage->OnCursor();
	};
	void NotOnCursor() override {
		_pImage->NotOnCursor();
	};
	inline void SetFontSize(int setSize){ _pText->SetFontSize(setSize); }

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
