#pragma once
/*
* Ishihara
* ステージの生成
*/
class StageCreator
{
public:
	void CreateStage();
private:
	int _stageData[7][7] = {
		{1, 2, 2, 2, 2, 2, 1},
		{3, 4, 0, 0, 0, 0, 3},
		{3, 0, 0, 0, 0, 0, 3},
		{1, 2, 2, 1, 2, 2, 1},
		{3, 0, 0, 0, 0, 0, 3},
		{3, 0, 0, 0, 0, 0, 3},
		{1, 2, 2, 2, 2, 2, 1},
	};


};

