#include "../header/FaseManager.h"

void FaseManager::Init()
{
	// フェーズのリストを初期化
	_faseList.clear();
	_faseList.push_back(new FaseSelect());
	_faseList.push_back(new FaseStandby());
	_faseList.push_back(new FaseMain());
	_faseList.push_back(new FaseResult());
}

void FaseManager::Proc()
{
	for (int i = 0, max = (int)_faseList.size(); i < max; i++)
	{
		// 初期化してフェーズのループを回す
		_faseList[i]->Init();
		_faseList[i]->ProcLoop();
		_faseList[i]->Teardown();
	}
}

void FaseManager::Teardown()
{
	for (int i = 0, max = (int)_faseList.size(); i < max; i++)
	{
		_faseList[i]->Teardown();
		delete _faseList[i];
	}
	_faseList.clear();
}