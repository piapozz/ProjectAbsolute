#pragma once
#include "Const.h"
#include <vector>
#include "RouteSearcher.h"
#include "SecureRoom.h"
#include "BaseEntity.h"
class Vector2;
/*
* Ishihara
* ステージの生成
*/
class StageManager
{
public:
	// ステージデータ
	static std::vector<std::vector<int>> _stageData;
	
	StageManager() { Init(); }
	~StageManager();

	/// <summary>
	/// 初期化
	/// </summary>
	void Init();
	/// <summary>
	/// ステージ生成
	/// </summary>
	void CreateStage();
	/// <summary>
	/// 区画がつながっているかどうか
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="type"></param>
	/// <returns></returns>
	int CheckSectionSize(int x, int y, SectionType type);
	/// <summary>
	/// A* アルゴリズムで経路を探索する
	/// </summary>
	/// <param name="start">スタート位置（ワールド座標）</param>
	/// <param name="goal">ゴール位置（ワールド座標）</param>
	/// <returns>Node* の経路リスト（ゴールからスタート方向）</returns>
	static std::vector<Vector2> FindPath(Vector2 start, Vector2 goal);
	/// <summary>
	/// ステージのデータを取得
	/// </summary>
	/// <param name="stageData"></param>
	void SetStageData(std::vector<std::vector<int>> stageData) { _stageData = stageData; }
	/// <summary>
	/// ステージがあるかどうか
	/// </summary>
	/// <param name="pos"></param>
	/// <returns></returns>
	bool CheckPosOnStage(Vector2 pos);
	/// <summary>
	/// 敵の設定
	/// </summary>
	/// <param name="entity"></param>
	/// <param name="index"></param>
	void SetEntity(BaseEntity& entity, int index){_secureRoomList[index]->SetEntity(&entity); }
private:
	// 事前に初期化された訪問フラグ
	std::vector<std::vector<bool>> _visited;
	std::vector<SecureRoom*> _secureRoomList;

};