#pragma once
#include "../header/BaseUIScreen.h"
#include <functional>
/*
* Ishihara
* UIスクリーンボタン
*/
class UIScreenButton : public BaseUIScreen
{
public:
	UIScreenButton() {}
	UIScreenButton(Layer setLayer)
		: BaseUIScreen(setLayer) {}
	UIScreenButton(Layer setLayer, int setDrawHandle)
		: BaseUIScreen(setLayer, setDrawHandle) {}
	UIScreenButton(const UIScreenButton& obj)
		: BaseUIScreen(obj) {}
	~UIScreenButton() {}
	void Init(Vector2 setPosition, Vector2 setSize) override;
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	void ClickEvent() override { _callback(); }
	/// <summary>
	/// コールバックの設定
	/// </summary>
	/// <param name="callback"></param>
	void SetCallback(std::function<void()> callback) { _callback = callback; }
private:
	// コールバック
	std::function<void()> _callback;
	// スクリーン座標
	Vector2 _screenPos;
};
