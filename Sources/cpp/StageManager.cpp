#include "../header/StageManager.h"
#include "../header/SectionRoom.h"
#include "../header/SectionCorridor.h"
#include "../header/SectionConnect.h"
#include "../header/SecureRoom.h"
#include "../header/Const.h"
#include "../header/ObjectManager.h"
#include "../header/CommonModule.h"
#include "../header/RouteSearcher.h"

StageManager::~StageManager() 
{
	// 二次元ベクターをクリア
	for (auto& row : _stageData){ row.clear(); }
	_stageData.clear();
	for (auto& row : _visited){ row.clear(); }
	_visited.clear();

	delete _routeSearcher;
}

void StageManager::Init(){  
   // ステージデータの初期化  
   _stageData = std::vector<std::vector<int>>{ // 修正: std::vector を使用して二次元配列を初期化  
       {1, 2, 2, 2, 2, 2, 1},  
       {3, 4, 0, 0, 0, 0, 3},  
       {3, 0, 0, 0, 0, 0, 3},  
       {1, 2, 2, 0, 2, 2, 1},  
       {3, 0, 0, 0, 0, 0, 3},  
       {3, 0, 0, 0, 0, 0, 3},  
       {1, 2, 2, 2, 2, 2, 1},  
   };  

   _routeSearcher = new RouteSearcher();
}
  
void StageManager::CreateStage()
{
	// 使用前に visited を初期化
	_visited = std::vector<std::vector<bool>>(
		STAGE_SIZE, // _stageData の行数に合わせる
		std::vector<bool>(STAGE_SIZE, false) // _stageData の列数に合わせる
		);

	// ステージの生成
	for (int i = 0; i < STAGE_SIZE; ++i)
	{
		for (int j = 0; j < STAGE_SIZE; ++j)
		{
			if (_visited[i][j]) continue; // 既に訪れた場所はスキップ
			// セクションの種類に応じて処理を分岐
			if (_stageData[i][j] == (int)SectionType::ROOM)
			{
				// 部屋を生成
				int size = CheckSectionSize(j, i, SectionType::ROOM);
				SectionRoom* room = new SectionRoom();
				room->Init(Vector2(j * SECTION_SIZE, i * -SECTION_SIZE), size);
				ObjectManager::AddObject(room);
			} 
			else if (_stageData[i][j] == (int)SectionType::CORRIDOR)
			{
				// 廊下を生成
				int size = CheckSectionSize(j, i, SectionType::CORRIDOR);
				SectionCorridor* corrider = new SectionCorridor();
				corrider->Init(Vector2(j * SECTION_SIZE, i * -SECTION_SIZE), size);
				ObjectManager::AddObject(corrider);
			} 
			else if (_stageData[i][j] == (int)SectionType::CONNECT)
			{
				// 接合部を生成
				int size = CheckSectionSize(j, i, SectionType::CONNECT);
				SectionConnect* connect = new SectionConnect();
				connect->Init(Vector2(j * SECTION_SIZE, i * -SECTION_SIZE), size);
				ObjectManager::AddObject(connect);
			} 
			else if (_stageData[i][j] == 4)
			{
				// 収容所を生成
				/*SecureRoom* secure = new SecureRoom();
				secure->Init(Vector2(j * SECTION_SIZE, i * -SECTION_SIZE), 1);
				ObjectManager::AddObject(secure);*/
				SectionRoom* room = new SectionRoom();
				room->Init(Vector2(j * SECTION_SIZE, i * -SECTION_SIZE), 0);
				ObjectManager::AddObject(room);
			}
		}
	}
}

/// <summary>
/// いくつつながっているかを調べる
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="type"></param>
/// <returns></returns>
int StageManager::CheckSectionSize(int x, int y, SectionType type)
{
	// 範囲外チェック
	if (y < 0 || y >= STAGE_SIZE || x < 0 || x >= STAGE_SIZE)
		return 0;
	// 既に訪れている or 種類が異なる場合は無視
	if (_visited[y][x] || _stageData[y][x] != (int)type)
		return 0;
	_visited[y][x] = true;

	int count = 1;
	// 上下左右に再帰
	count += CheckSectionSize(x, y - 1, type); // 上
	count += CheckSectionSize(x, y + 1, type); // 下
	count += CheckSectionSize(x - 1, y, type); // 左
	count += CheckSectionSize(x + 1, y, type); // 右

	return count;
}

std::vector<Vector2> StageManager::FindPath(Vector2 start, Vector2 goal)
{
	return _routeSearcher->RouteSearch(_stageData, start, goal);
}
