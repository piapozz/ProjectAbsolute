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
	inline virtual void Init(){};
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
	inline virtual void Teardown() {
		ObjectManager::Instance().AllClear(); };

protected:
	/// <summary>
	/// カーソルが乗っているときの処理
	/// </summary>
	/// <param name="pos"></param>
	virtual void OnCursorProc(Vector2 pos){}
	/// <summary>
	/// 左クリックを押したときの処理
	/// </summary>
	/// <param name="pos"></param>
	virtual void LPushInputProc(Vector2 pos){}
	/// <summary>
	/// 右クリックを押したときの処理
	/// </summary>
	/// <param name="pos"></param>
	virtual void RPushInputProc(Vector2 pos){}
	/// <summary>
	/// 左クリックをドラックしているときの処理
	/// </summary>
	/// <param name="pos"></param>
	virtual void LDrackInputProc(Vector2 pos, Vector2 oldPos){}
	/// <summary>
	/// 右クリックをドラックしているときの処理
	/// </summary>
	/// <param name="pos"></param>
	virtual void RDrackInputProc(Vector2 pos, Vector2 oldPos){}
	/// <summary>
	/// 左クリックを離したときの処理
	/// </summary>
	/// <param name="pos"></param>
	/// <param name="oldPos"></param>
	virtual void LReleaseInputProc(Vector2 pos, Vector2 oldPos){}
	/// <summary>
	/// 右クリックを離したときの処理
	/// </summary>
	/// <param name="pos"></param>
	/// <param name="oldPos"></param>
	virtual void RReleaseInputProc(Vector2 pos, Vector2 oldPos){}
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