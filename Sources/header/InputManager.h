#pragma once
#include "DxLib.h"
#include "functional"

/*
 * Sein
 * キーボードとマウスの入力を受け取り、イベントを管理
 */
class InputManager
{
public:
	// マウス情報を管理
	struct MouseStatus
	{
		int CURSOR_POS_X;
		int CURSOR_POS_Y;
	};

	// マウスのボタンの種類定義
	enum MouseButton
	{
		NONE = -1,
		LEFT_CLICK = MOUSE_INPUT_LEFT,
		RIGHT_CLICK = MOUSE_INPUT_RIGHT ,
	};

	InputManager();
	~InputManager();

	bool CheckClick(MouseButton button);
	void ExecuteCallback();
	void UpdataMouseCursor(MouseStatus mouseStatus);

	inline MouseStatus GetCursorPos();
	inline void SetCallback(std::function<void()> callback);

private:
	// マウスカーソル座標を保持
	MouseStatus cursorPos;
	// Functionを保持する変数
	std::function<void()> callbackFunc;
	// マウスの過去の状態を格納
	int oldMouseInput;
};
