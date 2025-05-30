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
	/// クリックの状態を確認する
	/// </summary>
	/// <returns></returns>
	int CheckClickState();
	/// <summary>
	/// コールバックで設定された関数を実行
	/// </summary>
	void ExecuteCallback();
	/// <summary>
	/// カーソルのスクリーン座標の取得
	/// </summary>
	/// <param name="mouseStatus"></param>
	Vector2 GetCursorScreenPos();

	inline void SetLPushCallback(std::function<void(Vector2 pos)> Callback){ _LPushAction = Callback; }
	inline void SetRPushCallback(std::function<void(Vector2 pos)> Callback){ _RPushAction = Callback; }
	inline void SetLDrackCallback(std::function<void(Vector2 pos)> Callback){ _LDrackAction = Callback; }
	inline void SetRDrackCallback(std::function<void(Vector2 pos)> Callback){ _RDrackAction = Callback; }
	inline void SetLReleaseCallback(std::function<void(Vector2 pos, Vector2 oldPos)> Callback){ _LReleaseAction = Callback; }
	inline void SetRReleaseCallback(std::function<void(Vector2 pos, Vector2 oldPos)> Callback){ _RReleaseAction = Callback; }
	inline void SetWheelRotCallback(std::function<void(Vector2 pos, int rot)> Callback){ _WheelRotAction = Callback; }
	inline void SetEscapeCallback(std::function<void()> Callback){ _EscapePushAction = Callback; }

private:
	// 左クリックを押したときのコールバック
	std::function<void(Vector2 pos)> _LPushAction;
	// 右クリックを押したときのコールバック
	std::function<void(Vector2 pos)> _RPushAction;
	// 左クリックをドラックしているときのコールバック
	std::function<void(Vector2 pos)> _LDrackAction;
	// 右クリックをドラックしているときのコールバック
	std::function<void(Vector2 pos)> _RDrackAction;
	// 左クリックを離したときのコールバック
	std::function<void(Vector2 pos, Vector2 oldPos)> _LReleaseAction;
	// 右クリックを離したときのコールバック
	std::function<void(Vector2 pos, Vector2 oldPos)> _RReleaseAction;
	// ホイールを回転したときのコールバック
	std::function<void(Vector2 pos, int rot)> _WheelRotAction;
	// Escapeキーを押したときのコールバック
	std::function<void()> _EscapePushAction;
	// 左クリックが押されたスクリーン座標
	Vector2 _oldLClickScreenPos;
	// 右クリックが押されたスクリーン座標
	Vector2 _oldRClickScreenPos;
	// 左クリックの状態
	int _LClickState;
	// 右クリックの状態
	int _RClickState;
	// 左クリックが押されているか
	bool _isLPressed;
	// 右クリックが押されているか
	bool _isRPressed;
};
