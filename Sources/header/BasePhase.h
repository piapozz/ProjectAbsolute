#pragma once
#include<functional>
#include "ObjectManager.h"
class InputManager;
/*
 * Sakakura
 * フェーズの基底
 */
class BasePhase
{
public:
	inline BasePhase(){};
	inline ~BasePhase(){};

	/// <summary>
	/// 初期化
	/// </summary>
	inline virtual void Init() { ObjectManager::Init();};
	/// <summary>
	//// 処理のループ
	// </summary>
	void ProcLoop();
	/// <summary>
	/// 処理
	/// </summary>
	/// <returns>終了したか否か</returns>
	inline virtual bool Proc() = 0;
	/// <summary>
	/// 破棄
	/// </summary>
	inline virtual void Teardown() = 0;

protected:
	/// <summary>
	/// 左クリックしたときの処理
	/// </summary>
	virtual void LClickInputProc(Vector2 pos, Vector2 oldPos){};
	/// <summary>
	/// 右クリックしたときの処理
	/// </summary>
	virtual void RClickInputProc(Vector2 pos, Vector2 oldPos){};
	/// <summary>
	/// ホイールを回転したときの処理
	/// </summary>
	virtual void WheelRotInputProc(Vector2 pos, int rot){};
	/// <summary>
	/// Escapeキーを押したときの処理
	/// </summary>
	virtual void EscapeInputProc(){};

	InputManager* pInputManager;
};