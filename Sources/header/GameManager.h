#pragma once
#include "DxLib.h"
#include "../header/FaseManager.h"

/*
 * Sein
 * メインゲームの進行を管理
 */
class GameManager
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Init();
	/// <summary>
	/// メイン処理
	/// </summary>
	void Proc();
	bool GetGameEnd ( );

private:
	FaseManager _faseManager;
	// ゲームが終了したかを保持
	bool _gameEnd;

	GameManager();
	~GameManager();
};