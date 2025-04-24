#include "../header/StageManager.h"
#include "../header/SectionRoom.h"
#include "../header/SectionCorridor.h"
#include "../header/SectionConnect.h"
#include "../header/SecureRoom.h"
#include "../header/Const.h"
#include "../header/CommonModule.h"
#include "../header/RouteSearcher.h"
#include "../header/PhaseMain.h"
#include "../header/UIButton.h"

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
				Vector2 pos = Vector2((j + size / 2.0f) * SECTION_SIZE_X, -(i + size / 2.0f) * SECTION_SIZE_Y);
				room->Init(pos, Vector2(size * SECTION_SIZE_X, size * SECTION_SIZE_Y));
				UIButton* button = new UIButton();
				button->Init(pos, Vector2(size * SECTION_SIZE_X, size * SECTION_SIZE_Y));
				button->SetActive(true);
				button->SetText("部屋");
				button->SetLayer(Layer::NONE_INTERACT);
			} 
			else if (_stageData[i][j] == (int)SectionType::CORRIDOR)
			{
				// 廊下を生成
				int size = CheckSectionSize(j, i, SectionType::CORRIDOR);
				SectionCorridor* corrider = new SectionCorridor();
				Vector2 pos = Vector2((j + size / 2.0f) * SECTION_SIZE_X, -(i + 1 / 2.0f) * SECTION_SIZE_Y);
				corrider->Init(pos, Vector2(size * SECTION_SIZE_X, SECTION_SIZE_Y));
				UIButton* button = new UIButton();
				button->Init(pos, Vector2(size * SECTION_SIZE_X, SECTION_SIZE_Y));
				button->SetActive(true);
				button->SetText("廊下");
				button->SetLayer(Layer::NONE_INTERACT);
			} 
			else if (_stageData[i][j] == (int)SectionType::CONNECT)
			{
				// 接合部を生成
				int size = CheckSectionSize(j, i, SectionType::CONNECT);
				SectionConnect* connect = new SectionConnect();
				Vector2 pos = Vector2((j + 1 / 2.0f)* SECTION_SIZE_X, -(i + size / 2.0f) * SECTION_SIZE_Y);
				connect->Init(pos, Vector2(SECTION_SIZE_X, size * SECTION_SIZE_Y));
				UIButton* button = new UIButton();
				button->Init(pos, Vector2(SECTION_SIZE_X, size * SECTION_SIZE_Y));
				button->SetActive(true);
				button->SetText("接続部");
				button->SetLayer(Layer::NONE_INTERACT);
			} 
			else if (_stageData[i][j] == (int)SectionType::SECURE)
			{
				// 収容所を生成
				int size = CheckSectionSize(j, i, SectionType::SECURE);
				SecureRoom* secure = new SecureRoom();
				Vector2 pos = Vector2((j + size / 2.0f) * SECTION_SIZE_X, -(i + size / 2.0f) * SECTION_SIZE_Y);
				secure->Init(pos, Vector2(size * SECTION_SIZE_X, size * SECTION_SIZE_Y));
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
	if (pos.x < 0 || pos.x >= STAGE_SIZE * SECTION_SIZE_X ||
		pos.y < -STAGE_SIZE * SECTION_SIZE_Y || pos.y > 0)
	{
		return false;
	}
	int y = (int)(pos.x / SECTION_SIZE_X);
	int x = (int)(-pos.y / SECTION_SIZE_Y);
	// 区画が存在しない、または接続部、収容所は false
	if (_stageData[x][y] == (int)SectionType::CONNECT || 
		_stageData[x][y] == (int)SectionType::NONE ||
		_stageData[x][y] == (int)SectionType::SECURE)
	{
		return false;
	}
	return true;
}