#pragma once
#include "BaseUI.h"
#include <string>
#include <functional>

class UIButton: public BaseUI
{
public:
	UIButton() {}
	UIButton(Layer setLayer)
		: BaseUI(setLayer) {}
	UIButton(Layer setLayer, int setDrawHandle)
		: BaseUI(setLayer, setDrawHandle) {}
	UIButton(const UIButton& obj)
		: BaseUI(obj) {}
	~UIButton() {}
	void Init(Vector2 setPosition, Vector2 setSize) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	void ClickEvent() override {_callback();}

	/// <summary>
	/// テキストの設定
	/// </summary>
	/// <param name="text"></param>
	void SetButtonText(const std::string& text) { _buttonText = text; }
	/// <summary>
	/// コールバックの設定
	/// </summary>
	/// <param name="callback"></param>
	void SetCallback(std::function<void()> callback) {_callback = callback;}
private:
	// ボタンの文字
	std::string _buttonText;
	std::string prevText = "";
	// コールバック
	std::function<void()> _callback;
};

