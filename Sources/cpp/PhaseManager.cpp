#include "../header/PhaseManager.h"
#include "../header/ObjectManager.h"

void PhaseManager::Init()
{
	// フェーズのリストを初期化
	_phaseList.clear();
	_phaseList.push_back(new PhaseSelect());
	_phaseList.push_back(new PhaseStandby());
	_phaseList.push_back(new PhaseMain());
	_phaseList.push_back(new PhaseResult());
}

void PhaseManager::Proc()
{
	for (int i = 0, max = (int)_phaseList.size(); i < max; i++)
	{
		// 初期化してフェーズのループを回す
		_phaseList[i]->Init();
		_phaseList[i]->ProcLoop();
		_phaseList[i]->Teardown();
	}
}

void PhaseManager::Teardown()
{
	for (int i = 0, max = (int)_phaseList.size(); i < max; i++)
	{
		_phaseList[i]->Teardown();
		delete _phaseList[i];
	}
	_phaseList.clear();
}