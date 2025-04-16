#pragma once
#include "Const.h"
/*
* Ishihara
* ステージの生成
*/
class StageManager
{
public:
	void CreateStage();
	int CheckSectionSize(int x, int y, SectionType type);
private:

	int _stageData[STAGE_SIZE][STAGE_SIZE] = {
		{1, 2, 2, 2, 2, 2, 1},
		{3, 4, 0, 0, 0, 0, 3},
		{3, 0, 0, 0, 0, 0, 3},
		{1, 2, 2, 0, 2, 2, 1},
		{3, 0, 0, 0, 0, 0, 3},
		{3, 0, 0, 0, 0, 0, 3},
		{1, 2, 2, 2, 2, 2, 1},
	};

	// 事前に初期化された訪問フラグ
	std::vector<std::vector<bool>> _visited;
};

