#pragma once
#include "DxLib.h"
#include "functional"
#include "../header/CommonModule.h"

/*
 * Sein
 * キーボードとマウスの入力を受け取り、イベントを管理
 */
class InputManager
{
public:
	InputManager();
	~InputManager();

	/// <summary>
	/// クリックされたかを取得
	/// </summary>
	/// <param name="button"></param>
	/// <param name="isPush"></param>
	/// <returns></returns>
	bool IsClick(int button);
	/// <summary>
	/// コールバックで設定された関数を実行
	/// </summary>
	void ExecuteCallback();
	/// <summary>
	/// カーソルのスクリーン座標の取得
	/// </summary>
	/// <param name="mouseStatus"></param>
	Vector2 GetCursorScreenPos();
	/// <summary>
	/// カーソルのスクリーン座標からワールド座標の取得
	/// </summary>
	/// <returns></returns>
	Vector2 GetCursorWorldPos(Vector2 screenPos);

	inline void SetLClickCallback(std::function<void(Vector2 pos, Vector2 oldPos)> Callback){ _LClickAction = Callback; }
	inline void SetRClickCallback(std::function<void(Vector2 pos, Vector2 oldPos)> Callback){ _RClickAction = Callback; }
	inline void SetWheelRotCallback(std::function<void(Vector2 pos, int rot)> Callback){ _WheelRotAction = Callback; }
	inline void SetEscapeCallback(std::function<void()> Callback){ _EscapePushAction = Callback; }

private:
	// 左クリックしたときのコールバック
	std::function<void(Vector2 pos, Vector2 oldPos)> _LClickAction;
	// 右クリックしたときのコールバック
	std::function<void(Vector2 pos, Vector2 oldPos)> _RClickAction;
	// ホイールを回転したときのコールバック
	std::function<void(Vector2 pos, int rot)> _WheelRotAction;
	// Escapeキーを押したときのコールバック
	std::function<void()> _EscapePushAction;
	// 左クリックが押されたスクリーン座標
	Vector2 _oldLClickScreenPos;
	// 右クリックが押されたスクリーン座標
	Vector2 _oldRClickScreenPos;
};
