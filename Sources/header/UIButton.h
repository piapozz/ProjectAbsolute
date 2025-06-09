#pragma once
#include "UIText.h"
#include <functional>
/*
* Ishihara
* UIボタン
*/
class UIButton: public BaseUI
{
public:
	UIButton() {}
	UIButton(Vector2 pos, Vector2 size, LayerSetting layerSetting){
		Init(pos, size, layerSetting);
	}
	UIButton(UISetting setting, std::function<void()> callback, LayerSetting layerSetting) {
		Init(setting.m_position, setting.m_size, layerSetting);
		SetSize(setting.m_size.x);
		SetText(setting.m_text);
		SetCallback(callback);
	}
	UIButton(Layer setLayer)
		: BaseUI(setLayer) {}
	UIButton(Layer setLayer, int setDrawHandle)
		: BaseUI(setLayer, setDrawHandle) {}
	UIButton(const UIButton& obj)
		: BaseUI(obj) {}
	~UIButton() {}
	void Init(Vector2 setPosition, Vector2 setSize, LayerSetting layerSetting) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	void ClickEvent() override {_callback();}

	static std::string StaticTypeName() {
		return "UIButton";
	}

	/// <summary>
	/// コールバックの設定
	/// </summary>
	/// <param name="callback"></param>
	void SetCallback(std::function<void()> callback) {_callback = callback;}
private:

	// コールバック
	std::function<void()> _callback;
};

