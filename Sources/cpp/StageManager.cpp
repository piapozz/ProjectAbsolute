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
#include "../header/ObjectFactory.h"

StageManager::~StageManager() 
{

}

void StageManager::Init()
{

}

void StageManager::CreateStage(int divisionCount)
{
	_divisionList.clear();
	_stageData.clear();
	DivisionCreater creater = DivisionCreater::Instance();
	for(int i = 0; i < divisionCount + 1; i++)
	{
		// 区画プリセットの設定
		creater.SetDivisionPreset(_divisionPreset);
		Vector2 anchorPos = _anchorList[i];
		Division* division = creater.CreateDivision(anchorPos);
		// 区画番号の設定
		division->SetDivisionIndex(i);

		_divisionList.push_back(division);

		// アンカーから結合方向を決定
		AttachDirection direction = AttachDirection::Right;
		anchorPos.normalize();

		if (anchorPos.x > 0 && anchorPos.y == 0) {
			direction = AttachDirection::Right;
		} else if (anchorPos.x < 0 && anchorPos.y == 0) {
			direction = AttachDirection::Left;
		} else if (anchorPos.x == 0 && anchorPos.y < 0) {
			direction = AttachDirection::Top;
		}
		else if (anchorPos.x == 0 && anchorPos.y > 0) {
			direction = AttachDirection::Bottom;
		}

		// ステージデータに結合
		if (_stageData.size() == 0){
			_stageData = _divisionPreset;
		}
		else{
			Attach2DArray(_stageData, _divisionPreset, direction, Align::Center);
		}
	}
}

std::vector<Vector2> StageManager::FindPath(Vector2 start, Vector2 goal)
{
	// ステージデータの初期化
	return RouteSearcher::RouteSearch(_stageData, start, goal);
}

bool StageManager::CheckPosOnStage(Vector2 pos)
{
	// ステージの範囲外の場合は false を返す
	if (pos.y < -(int)(_stageData.size()) * SECTION_SIZE_Y || pos.y > 0 ||
		pos.x < 0 || pos.x >= _stageData[0].size() * SECTION_SIZE_X)
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

void StageManager::SetEntity(std::vector<BaseEntity*> entityList, int divisionIndex)
{
	for (int i = 0; i < entityList.size(); i++)
	{
		if (entityList[i] == nullptr) continue;

		_divisionList[divisionIndex]->SetEntity(entityList[i], i);
	}
}