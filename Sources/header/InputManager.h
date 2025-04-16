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

	/// <summary>
	/// クリックが押されているかを判定
	/// </summary>
	/// <param name="button"></param>
	/// <returns></returns>
	void OnClick(MouseButton button);
	/// <summary>
	/// コールバックで設定された関数を実行
	/// </summary>
	void ExecuteCallback();
	/// <summary>
	/// カーソル情報の更新
	/// </summary>
	/// <param name="mouseStatus"></param>
	void UpdataMouseCursor(MouseStatus mouseStatus);

	inline MouseStatus GetCursorPos(){ return _cursorPos; }
	inline void SetLClickCallback(std::function<void()> Callback){ _LPushAction = Callback; }
	inline void SetRClickCallback(std::function<void()> Callback){ _RPushAction = Callback; }
	inline void SetLReleaseCallback(std::function<void()> Callback){ _LReleaseAction = Callback; }
	inline void SetRReleaseCallback(std::function<void()> Callback){ _RReleaseAction = Callback; }

private:
	// マウスカーソル座標を保持
	MouseStatus _cursorPos;
	// 左クリックを押したときのコールバック
	std::function<void()> _LPushAction;
	// 右クリックを押したときのコールバック
	std::function<void()> _RPushAction;
	// 左クリックを離したときのコールバック
	std::function<void()> _LReleaseAction;
	// 右クリックを離したときのコールバック
	std::function<void()> _RReleaseAction;
	// マウスの過去の状態を格納
	int _oldMouseInput;
};
