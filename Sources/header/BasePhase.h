#pragma once
#include<functional>
#include "ObjectManager.h"

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
	// オブジェクトをセットするコールバック
	std::function<void()> SetObject;
	// オブジェクトを破棄するコールバック
	std::function<void()> DeleteObject;

	/// <summary>
	/// 入力に応じた処理
	/// </summary>
	virtual void InputProc() = 0;
};