#pragma once
#include "DxLib.h"
#include "vector"
#include "../header/DataManager.h"

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

private:
	struct EntityRooms
	{

	};

	struct DayData
	{
		int date;
		std::vector<EntityRooms> entityRoomList;
	};

	// ゲームが終了したかを保持
	bool _gameEnd;

	bool CheckGameEnd();
};