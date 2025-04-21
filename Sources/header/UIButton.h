#pragma once
#include "BaseUI.h"
#include <string>

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

	/// <summary>
	/// 表示の切り替え
	/// </summary>
	/// <param name="active"></param>
	void SetActive(bool active);
	/// <summary>
	/// テキストの設定
	/// </summary>
	/// <param name="text"></param>
	void SetButtonText(const std::string& text) { _buttonText = text; }
	/// <summary>
	/// 画面に追従させるかどうか
	/// </summary>
	/// <param name="is2D"></param>
	void Set2D(bool is2D) { _is2D = is2D; }
private:
	// ボタンの文字
	std::string _buttonText;
	// "2Dか3Dか
	bool _is2D;
};

