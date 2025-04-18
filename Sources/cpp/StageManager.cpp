#include "../header/StageManager.h"
#include "../header/SectionRoom.h"
#include "../header/SectionCorridor.h"
#include "../header/SectionConnect.h"
#include "../header/SecureRoom.h"
#include "../header/Const.h"
#include "../header/ObjectManager.h"
#include "../header/CommonModule.h"
#include "../header/RouteSearcher.h"
#include "../header/PhaseMain.h"

std::vector<std::vector<int>> StageManager::_stageData;

StageManager::~StageManager() 
{
	//収容所データの解放
	for (BaseObject* secure : _secureRoomList)
	{		
		secure->Teardown();
		delete secure;
	}
}

void StageManager::Init()
{  
	_secureRoomList.clear();
}
  
void StageManager::CreateStage()
{
	// 使用前に visited を初期化
	_visited = std::vector<std::vector<bool>>(
		// _stageData の行数に合わせる
		STAGE_SIZE,
		// _stageData の列数に合わせる
		std::vector<bool>(STAGE_SIZE, false) 
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
				SecureRoom* secure = new SecureRoom();
				secure->Init(Vector2(j * SECTION_SIZE, i * -SECTION_SIZE), 1);
				ObjectManager::AddObject(secure);
				// 収容所のリストに追加
				_secureRoomList.push_back(secure);
			}
		}
	}
}

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
	count += CheckSectionSize(x, y - 1, type);
	count += CheckSectionSize(x, y + 1, type);
	count += CheckSectionSize(x - 1, y, type);
	count += CheckSectionSize(x + 1, y, type);

	return count;
}

std::vector<Vector2> StageManager::FindPath(Vector2 start, Vector2 goal)
{
	// ステージデータの初期化
	return RouteSearcher::RouteSearch(_stageData, start, goal);
}

bool StageManager::CheckPosOnStage(Vector2 pos)
{
	// ステージの範囲外の場合は false を返す
	if (pos.x < 0 || pos.x >= STAGE_SIZE * SECTION_SIZE ||
		pos.y < -STAGE_SIZE * SECTION_SIZE || pos.y > 0)
	{
		return false;
	}
	// 区画が存在しない、または接続部は false
	if (_stageData[(int)(-pos.y / SECTION_SIZE)][(int)(pos.x / SECTION_SIZE)] == (int)SectionType::CONNECT || 
		_stageData[(int)(-pos.y / SECTION_SIZE)][(int)(pos.x / SECTION_SIZE)] == (int)SectionType::NONE)
	{
		return false;
	}
	return true;
}