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

	GameManager();
	~GameManager();

	/// <summary>
	/// 初期化
	/// </summary>
	void Init();
	bool GetGameEnd ( );

private:
	PhaseManager* _pPhaseManager;
	// ゲームが終了したかを保持
	bool _gameEnd;
};