#pragma once
#include "DxLib.h"
#include "../header/PhaseManager.h"

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
	PhaseManager _phaseManager;
	// ゲームが終了したかを保持
	bool _gameEnd;

	GameManager();
	~GameManager();
};