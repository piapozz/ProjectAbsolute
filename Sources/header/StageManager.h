#pragma once
#include "Const.h"
#include <vector>
#include "RouteSearcher.h"
#include "BaseEntity.h"
#include "DivisionCreater.h"
class Vector2;
/*
生成アンカーの設定
配列の結合
区画の保持
*/
class StageManager
{
public:

	static StageManager& Instance() {
		static StageManager instance;
		return instance;
	}

	StageManager() {
		Init();
	}
	~StageManager();

	/// <summary>
	/// 初期化
	/// </summary>
	void Init();

	/// <summary>
	/// A* アルゴリズムで経路を探索する
	/// </summary>
	/// <param name="start">スタート位置（ワールド座標）</param>
	/// <param name="goal">ゴール位置（ワールド座標）</param>
	/// <returns>Node* の経路リスト（ゴールからスタート方向）</returns>
	std::vector<Vector2> FindPath(Vector2 start, Vector2 goal);
	/// <summary>
	/// ステージのデータを取得
	/// </summary>
	/// <param name="stageData"></param>
	void SetStageData(std::vector<std::vector<int>> stageData) {
		_stageData = stageData;
	}
	/// <summary>
	/// ステージがあるかどうか
	/// </summary>
	/// <param name="pos"></param>
	/// <returns></returns>
	bool CheckPosOnStage(Vector2 pos);

	// ステージ生成
	void CreateStage(int divisionCount);

	void SetEntity(std::vector<BaseEntity*> entityList, int divisionIndex);

	BaseSection* GetRandomSection(int divisionIndex)
	{
		return _divisionList[divisionIndex]->GetRandomSection();
	}

	std::vector<SecureRoom*> GetSecureRoom(int divisionIndex)
	{
		return _divisionList[divisionIndex]->GetSecureRoomList();
	}

	BaseSection* GetRespawnSection(int divisionIndex)
	{
		return _divisionList[divisionIndex]->GetRespawnPoint();
	}

	/// <summary>
	/// 1区画のエンティティの数
	/// </summary>
	/// <param name="divisionIndex"></param>
	/// <returns></returns>
	int GetEntityCount(int divisionIndex)
	{
		return _divisionList[divisionIndex]->GetEntityCount();
	}

private:
	std::vector<Division*> _divisionList;
	// ステージデータ
	std::vector<std::vector<int>> _stageData;

	// 拡張情報
	std::vector<Vector2> _anchorList = {
		Vector2(0, 0),
		Vector2(SECTION_SIZE_X * 7, 0),
		Vector2(0, -SECTION_SIZE_Y * 7),
		Vector2(SECTION_SIZE_X * 7, -SECTION_SIZE_Y * 7)
	};
	// プリセット
	std::vector<std::vector<int>> _divisionPreset =
	{
		{2, 3, 3, 3, 3, 3, 2},
		{4, 5, 0, 0, 0, 5, 4},
		{4, 0, 0, 0, 0, 0, 4},
		{2, 3, 3, 1, 3, 3, 2},
		{4, 0, 0, 0, 0, 0, 4},
		{4, 5, 0, 0, 0, 5, 4},
		{2, 3, 3, 3, 3, 3, 2}
	};
};
